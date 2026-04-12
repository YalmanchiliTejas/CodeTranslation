#include <iostream>
#include <vector>

int main(int argc, char const* argv[])
{
    int n;
    std::cin >> n;

    int current_height = 0;
    int result = 0;

    for(int i=0; i<n ;++i)
    {
        int in;
        std::cin >> in;
        if(current_height <= in)
        {
            result++;
            current_height = in;
        }
    }
    std::cout << result << std::endl;
    return 0;
}