#include <cstdio>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //freopen("debug.txt", "w", stderr);

    long N;

    scanf("%ld", &N);

    long a = N / 15;

    printf("%ld\n", N * 800 - a * 200);

    return 0;
}
