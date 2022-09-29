

#include <stdio.h>
#include <string.h>

#include "cubiomes_utils.c"

#include "finders.h"
#include "generator.h"
#include "util.h"

int main()
{
    //Set version and seed
    int mc = MC_1_19;
    uint64_t seed = 686689767;

    //Apply seed and dimension
    Generator g;
    setupGenerator(&g, mc, 0);
    applySeed(&g, DIM_OVERWORLD, seed);

    //Center point to search from, this example being X: 0, Z: 0 in the overworld. 
    int x = 0, z = 0;

    //Search range. This example will search in a 2000 block range around the given X/Z coordinates.
    int range = 2000;

    //Structure to search for.
    int structureType = Village;
    
    //This method returns a string containing the X/Z coordinates, and the distance in blocks it is 
    //from the given X/Z coordinates.
    char *result =  findStructures(structureType, g, range, x, z);

    //Iterate through the structures that were found
    char *token = strtok(result, "\n");
    if(token ==  NULL) 
    {   //Either no structures were found, or there was a config error
        printf("Error: %s", result);
    }

    while (token != NULL)
    {   //Prints out the coordinate data and distance
        printf("%s (X,Z,Distance): %s\n", struct2str(structureType), token);
        token = strtok(NULL, "\n");
    }
    return 0;
}