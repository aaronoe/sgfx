#include <sgfx/primitives.hpp>
#include <cstdlib>
using namespace std;

void sgfx::plot(window& target, point p, color::rgb_color col)
{
    int position = target.width * p.y + p.x;
    target.pixels[position] = col;
}

void sgfx::clear(window& target, color::rgb_color col)
{
    for(size_t i = 0; i < target.width * target.height; i++)
    {
        target.pixels[i] = col;
    }
}

void sgfx::hline(window& target, point p, std::uint16_t length, color::rgb_color col)
{
    int start = target.width * p.y + p.x;

    for(size_t i = start; i < start + length; i++)
    {
        target.pixels[i] = col;
    }
    
}

void sgfx::vline(window& target, point p, std::uint16_t length, color::rgb_color col)
{
    for(size_t i = p.y; i < p.y + length; i++)
    {
        int position = p.x + (i * target.width);
        target.pixels[position] = col;
    }
}

void sgfx::fill(window& target, rectangle rect, color::rgb_color col)
{
    for(size_t x = rect.top_left.x; x < rect.top_left.x + rect.size.width; x++)
    {
        for(size_t y = rect.top_left.y; y < rect.top_left.y + rect.size.height; y++)
        {
            size_t position = x + target.width * y;
            target.pixels[position] = col;
        };
    }
    
}

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

void sgfx::line(window& target, point p0, point p1, color::rgb_color col)
{
    int deltax = p1.x - p0.x;
    int deltay = p1.y - p0.y;

    double delta_error = abs(deltay / deltax);
    double error = 0.0;

    int y = p0.y;

    for(size_t x = p0.x; x < p1.x; x++)
    {
        plot(target, {x, y}, col);
        error += delta_error;
        if (error >= 0.5) {
            y += sgn(deltay);
            error = error - 1.0;
        }
    }
}
