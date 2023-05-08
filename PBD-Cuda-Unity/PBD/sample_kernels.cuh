#pragma once
#include "../cuda_include.h"
#include "../log.h"
#include <math_constants.h>
#include <device_launch_parameters.h>
#include <vector_functions.h>

void kernelCallerWriteBuffer(const dim3 dimGrid, const dim3 dimBlock,
                             float4 *vertexPtr, const int size,
                             const float time);