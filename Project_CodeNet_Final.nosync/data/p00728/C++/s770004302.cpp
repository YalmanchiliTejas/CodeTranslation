
#include <iostream>

// using namespace std;

int main()
{
    while (true)
    {
        int x;
        std::cin >> x;
        if (x == 0)
        {
            break;
        }
        long sum = 0;
        long max = 0;
        long min = 1000;
        for (int i = 0; i < x; i++)
        {
            long j;
            std::cin >> j;
            max = std::max(max, j);
            min = std::min(min, j);
            sum += j;
        }
        sum -= (min + max);
        std::cout << sum / (x - 2) << std::endl;
    }
}
