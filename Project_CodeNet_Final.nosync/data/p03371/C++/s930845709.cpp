#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
    long long A, B, C, X, Y;
    long long M, sum, tmp;

    scanf("%lld %lld %lld %lld %lld", &A, &B, &C, &X, &Y);

    C *= 2;

    M = min(X, Y);

    sum = min(M*A+M*B, M*C);

    M = abs(X-Y);

    if(X > Y)
        tmp = M*A;
    else if(X < Y)
        tmp = M*B;

    if(tmp > M*C)
        tmp = M*C;

    printf("%lld", sum+tmp);

    return 0;
}
