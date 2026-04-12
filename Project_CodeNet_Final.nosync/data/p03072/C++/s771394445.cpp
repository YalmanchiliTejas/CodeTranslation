#include <iostream>

int main()
{
    int N, H[100];
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> H[i];
    }

    int ans = 0;

    for (int i = 0; i < N; ++i)
    {
        bool visible = true;
        for (int j = 0; j < i; ++j)
        {
            if (H[i] < H[j])
            {
                visible = false;
                break;
            }
        }

        if (visible)
        {
            ans++;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
