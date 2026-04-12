#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
    const int price = 800;
    const int get = 200;
    const int times = 15;

    int N;
    if (scanf("%d", &N) < 1) return 0;

    printf("%d\n", price * N - (N / times) * get);
    return 0;
}
