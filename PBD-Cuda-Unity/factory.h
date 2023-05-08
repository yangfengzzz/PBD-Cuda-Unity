#pragma once

#include "Buffer/vertex_buffer_D3D11.h"


/// <summary>
/// Simple factory template to create some vertex buffer or texture in function of API type 
/// </summary>
namespace Factory
{
	VertexBuffer* createBuffer(void* bufferHandle, int size, UnityGfxRenderer apiType);
}

