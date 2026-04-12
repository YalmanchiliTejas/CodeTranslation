#include <iostream>
#include <vector>
#include <utility>

std::pair<std::vector<int>, std::vector<int>> read_input()
{
    std::vector<int> x;
    std::vector<int> y;

    int H, W;
    std::cin >> H >> W;

    std::string buf;
    for (int hi = 0; hi < H; ++hi)
    {
        std::cin >> buf;
        for (int wi = 0; wi < W; ++wi)
        {
            if (buf[wi] == '#')
            {
                x.push_back(hi);
                y.push_back(wi);
            }
        }
    }

    return {x, y};
}

void solve(const std::pair<std::vector<int>, std::vector<int>>& input)
{
    const std::vector<int> x = input.first;
    const std::vector<int> y = input.second;

    int tmp{};
    for (auto&& i : x)
    {
        if (tmp > i)
        {
            std::cout << "Impossible" << std::endl;
            return;
        }
        tmp = i;
    }

    tmp = 0;
    for (auto&& i : y)
    {
        if (tmp > i)
        {
            std::cout << "Impossible" << std::endl;
            return;
        }
        tmp = i;
    }

    std::cout << "Possible" << std::endl;
    return;
}

int main()
{
    solve(read_input());
    return 0;
}