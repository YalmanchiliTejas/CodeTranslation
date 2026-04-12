#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    int* H = new int[N];

    for (int i = 0; i < N; ++i)
    {
        std::cin >> H[i];
    }
    int max = H[0];
    int cnt = 1;
    for (int i = 1; i < N; ++i)
    {
        if (max <= H[i])
        {
            max = H[i];
            cnt++;
        }
    }

    std::cout << cnt << std::endl;

    delete[] H;

    return 0;
}