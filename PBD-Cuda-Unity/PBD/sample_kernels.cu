#include "sample_kernels.cuh"

__global__ void writeVertexBuffer(float4 *pos, int size, float time)
{
    unsigned int x = blockIdx.x * blockDim.x + threadIdx.x;

    // write output vertex
    if (x < size)
    {
        pos[x] = make_float4(cos(2 * CUDART_PI_F * time / x),
                             sin(2 * CUDART_PI_F * time / x), 0.0f, 1.0f);
    }
}

void kernelCallerWriteBuffer(const dim3 dimGrid, const dim3 dimBlock,
                             float4 *vertexPtr, const int size,
                             const float time)
{
    writeVertexBuffer<<<dimGrid, dimBlock>>>(vertexPtr, size, time);
}