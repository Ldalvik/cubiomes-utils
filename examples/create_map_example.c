

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

    //Center point to generate from, this example being X: 0, Z: 0 in the overworld. 
    int x = 0, z = 0;

    //The size of the map. Will generate from the center of the x/z coordinates.
    int width = 120*8, height = 120*8; //960x960

    //How many pixels per biome block. This example generates a 960x960 image. 
    //If the pixelScale was 4, it would be 3840x3840.
    int pixelScale = 1;

    //Scale of the map, 1 being the smallest.
    int scale = 1;

    //Depth (Y) of the biome generation.
    int depth = 100;

    //Generates a .ppm file with the given params.
    createMap(g, width, height, scale, depth, x, z, pixelScale);
    
    return 0;
}