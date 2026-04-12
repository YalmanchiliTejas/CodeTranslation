#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

uint64_t size(uint64_t n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return size(n - 1) * 2 + 3;
    }
}

uint64_t full_patty(uint64_t n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return full_patty(n - 1) * 2 + 1;
    }
}

uint64_t patty(uint64_t n, uint64_t x)
{
    if (n == 0)
    {
        return 1;
    }
    else if (size(n) <= x)
    {
        return full_patty(n);
    }
    else
    {
        auto prev_size = size(n - 1);
        if (x <= 1)
        {
            return 0;
        }
        else if (x <= prev_size + 1)
        {
            return patty(n - 1, x - 1);
        }
        else if (x == prev_size + 2)
        {
            return patty(n - 1, x - 1) + 1;
        }
        else if (x <= 2 * prev_size + 2)
        {
            return full_patty(n - 1) + 1 + patty(n - 1, x - prev_size - 2);
        }
        else
        {
            return full_patty(n - 1) * 2;
        }
    }
}

int main()
{
    uint64_t n, x;
    cin >> n >> x;

    cout << patty(n, x) << endl;
}
