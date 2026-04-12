#include <iostream>
#include <cstdlib>

int main()
{
    std::string stations;
    std::cin >> stations;
    bool ret = true;

    auto origin = stations[0];
    for(int i = 0; i < stations.length(); i++)
    {
        if(stations[i] != origin)
            ret = false;
    }

    if(!ret)
    {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }

    return EXIT_SUCCESS;
}

