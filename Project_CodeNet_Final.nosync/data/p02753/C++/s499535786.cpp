#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <memory>
#include <string>
#include <cstdio>
#include <ctime>
#include <complex>
#include <cassert>
#include <list>
#include <numeric>
#include <bitset>
#include <cstring>
#include <set>
#include<map>
#include<forward_list>

int main()
{
    std::string s;
    std::cin >> s;
    if((std::adjacent_find(s.begin(), s.end(), [](auto a, auto b){return a != b;}) != s.end()))
        std::cout << "Yes";
    else std::cout << "No";
}
