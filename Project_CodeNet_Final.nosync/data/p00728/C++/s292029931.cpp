#include <iostream>
#include <limits>

void doit(int N) {
    if (N < 3) {
        return;
    }
    int min = std::numeric_limits<int>::max();
    int max = std::numeric_limits<int>::min();
    int total = 0;
    int num = 0;
    
    for (int i = 0; i < N; i++) {
        int v;
        std::cin >> v;
        if (v < min) {
            min = v;
        }
        if (v > max) {
            max = v;
        }
        total += v;
        num++;
    }
    total -= (min + max);
    num -= 2;
    std::cout << (int)(((double)total) / num) << std::endl;
}

int main()
{
    int N;
    while(std::cin >> N) {
        doit(N);
    }
}