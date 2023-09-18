#include <iostream>
#include "simplestl.h"

int main()
{
    auto p = ncnn::make_pair<int, double>(1, 1.1);
    std::cout << " p.first: " << p.first << " p.second: " << p.second
              << std::endl;
}