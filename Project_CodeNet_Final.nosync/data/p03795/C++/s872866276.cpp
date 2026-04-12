#include <iostream>

using namespace std;
int N;

int main()
{
    scanf("%d", &N);
    int q = N/15;
    printf("%d\n", 800*N - 200*q);
    return 0;
}
