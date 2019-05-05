#include <sgfx/canvas.hpp>

void sgfx::draw(window& target, const canvas& img, point top_left)
{
    for(size_t x = top_left.x; x < top_left.x + img.width; x++)
    {
        for(size_t y = top_left.y; y < top_left.y + img.height; y++)
        {
            int position = y * target.width + x;
            int canvasPosition = y * img.width + x;

            target.pixels[position] = img.pixels[canvasPosition];
        }
        
    }
    
}
