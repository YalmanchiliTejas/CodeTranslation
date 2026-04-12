#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    int H, W;
    std::string a[110];
    std::cin >> H >> W;

    bool okH[110];
    bool okW[110];
    std::fill((bool *)okH, (bool *)(okH + 110), true);
    std::fill((bool *)okW, (bool *)(okW + 110), true);

    for (int i = 0; i < H; ++i)
        std::cin >> a[i];

    for (int i = 0; i < H; ++i)
    {
        for (size_t j = 0; j < a[i].size(); ++j)
            if (okW[i] && okH[j])
            {
                bool check = true;
                for (int k = 0; k < W; ++k)
                    if (a[i][k] == '#')
                    {
                        check = false;
                        break;
                    }
                if (check)
                {
                    okW[i] = false;
                    continue;
                }

                check = true;
                for (int k = 0; k < H; ++k)
                    if (a[k][j] == '#')
                    {
                        check = false;
                        break;
                    }
                if (check)
                {
                    okH[j] = false;
                    continue;
                }
                std::cout << a[i][j];
            }
        if (okW[i])
            std::cout << '\n';
    }

    return 0;
}