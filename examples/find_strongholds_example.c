

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

    //Center point to search from, this example being X: 0, Z: 0. 
    int x = 0, z = 0;

    //The amount of strongholds you want to search for.
    int limit = 5;

    //This method returns a string containing the X/Z coordinates, and the distance in blocks it is 
    //from the given X/Z coordinates.
    char *result = findStrongholds(g, x, z, limit);

    //Iterate through the strongholds
    char *token = strtok(result, "\n");

    if(token ==  NULL) 
    {   //Either no strongholds were found, or there was a config error
        printf("Error: %s", result);
    }

    while (token != NULL)
    {   //Prints out the coordinate data and distance
        printf("Stronghold (X,Z,Distance): %s\n", token);
        token = strtok(NULL, "\n");
    }
    
    return 0;
}