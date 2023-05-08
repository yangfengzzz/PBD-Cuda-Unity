#include "factory.h"

namespace Factory
{
VertexBuffer *createBuffer(void *bufferHandle, int size,
                           UnityGfxRenderer apiType)
{
    VertexBuffer *buffer = NULL;

#if SUPPORT_D3D11
    if (apiType == kUnityGfxRendererD3D11)
    {
        buffer = new VertexBuffer_D3D11(bufferHandle, size);
    }
#endif // if SUPPORT_D3D11
    // if SUPPORT_OPENGL_UNIFIED
#if SUPPORT_OPENGL_UNIFIED
    if (apiType == kUnityGfxRendererOpenGLCore ||
        apiType == kUnityGfxRendererOpenGLES20 ||
        apiType == kUnityGfxRendererOpenGLES30)
    {
        buffer = new VertexBuffer_OpenGLCoreES(bufferHandle, size);
    }
#endif

    // Unknown or unsupported graphics API
    return buffer;
}

} // namespace Factory