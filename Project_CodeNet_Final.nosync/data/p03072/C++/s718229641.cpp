#include <iostream>
#include <vector>

int main(void)
{
    int N;
    std::cin >> N;

    std::vector<int> H(N);
    for(int i = 0; i < N; ++i) std::cin >> H[i];

    int cnt = 1;
    for(int i = 1; i < N; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(H[i] < H[j])
            {
                break;
            }

            if(j + 1 == i)
            {
                cnt++;
            }
        }
    }

    std::cout << cnt << std::endl;
}