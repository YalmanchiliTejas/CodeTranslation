#include <cmath>
#include <iostream>
#include <vector>

int main()
{
    unsigned N;
    std::cin >> N;
    unsigned max = 0;
    std::vector<unsigned> t;
    for(unsigned i = 0; i != N; ++i)
    {
        unsigned buf;
        std::cin >> buf;
        if(buf > max)
        {
            max = buf;
        }
        t.push_back(buf);
    }
    unsigned long result = 0;
    unsigned root = sqrt(max);
    std::vector<unsigned long> up_cache(max+1);
    std::vector<unsigned long> down_cache(max+1);
    for(auto val : t)
    {
        unsigned target;
        if(val > root)
        {
            unsigned i = max / val;
            // クソコード注意: i!=0を利用
            if(down_cache[i])
            {
                i = down_cache[i];
            }
            else
            {
                for(; max % i != 0; --i) {}
                for(unsigned j = max / val; max % j != 0; --j)
                {
                    down_cache[j] = i;
                }
            }
            target = max / i;
        }
        else
        {
            unsigned i = val;
            if(up_cache[i])
            {
                i = up_cache[i];
            }
            else
            {
                for(; max % i != 0; ++i) {}
                for(unsigned j = val; max % j != 0; ++j)
                {
                    up_cache[j] = i;
                }
            }
            target = i;
        }
        result += target - val;
    }
    std::cout << result << '\n';
}
