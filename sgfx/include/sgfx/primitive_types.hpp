#ifndef SGFX_PRIMITIVE_TYPES_H
#define SGFX_PRIMITIVE_TYPES_H

#include <cstdint>

namespace sgfx
{
	
	struct point
	{
		int x;
		int y;
	};
	
	struct dimension
	{
		int width;
		int height;
	};
	
	struct rectangle
	{
		point top_left;
		dimension size;
	};

	struct vec
	{
		point start;
		point end;
	};
}

#endif
