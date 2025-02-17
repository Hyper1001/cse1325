#include <iostream>
#include <ostream>
#include "color.h"
#include <string>

Color::Color()
{
    _red = 255;
    _green = 255;
    _blue = 255;
    _reset = true;
}

Color::Color(int r, int g, int b) : _red{r}, _green {g}, _blue{b}
{
    if(r>255)
        _red = 255;
    else if(r<0)
        _red=0;
    if(g>255)
        _green = 255;
    else if(g<0)
        _green=0;
    if(b>255)
        _blue = 255;
    else if(b<0)
        _blue=0;
    _reset = false;
}

std::string Color::to_string()
{
    return "("+std::to_string(_red)+","+std::to_string(_green)+","+std::to_string(_blue)+")";
}

std::ostream& operator<<(std::ostream& ost, const Color& color)
{
    if(color._reset ==true)
    {
        ost << "\033[0m\n";
    }
    else
    {
        ost <<"\033[38;2;" <<std::to_string(color._red)<<";"<<std::to_string(color._green)<<";"<<std::to_string(color._blue)<<"m";
    }
    return ost;
}

std::istream& operator>>(std::istream& is, Color& color) //cant figure out errors
{
    std::cout<<"Please enter a RGB for red: ";
    std::cin>>color._red;
    std::cout<<"Please enter a RGB for green: ";
    std::cin>>color._green;
    std::cout<<"Please enter a RGB for blue: ";
    std::cin>>color._blue;
    color._reset = false;
}
