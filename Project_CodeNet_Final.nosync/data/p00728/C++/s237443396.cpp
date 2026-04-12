#include <iostream>

int main()
{
    int n, s = 0;
    while (std::cin >> n && n > 0) {
        int max, min, sum = 0;
        std::cin >> s;
        max = s;
        min = s;
        sum += s;

        for (int i = 0; i < n - 1; i++) {
            std::cin >> s;
            if (s > max)
                max = s;
            if (s < min)
                min = s;
            sum += s;
        }
        std::cout << (sum - max - min) / (n - 2) << '\n';
    }

    return 0;
}

