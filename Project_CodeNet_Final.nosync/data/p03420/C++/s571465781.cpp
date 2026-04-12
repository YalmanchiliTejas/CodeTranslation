#include <cstdio>
#include <iostream>
using namespace std;
int N, K;
long long result;

int main()
{
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++)
    {
        if(i - K >= 0)
        {
            int temp;
            result += (N / i) * (i - K);
            temp = N % i + 1 - K;
            if(temp > 0)
            {
                result += temp;
            }
        }
    }
    if(K == 0)
    {
        result -= N;
    }
    printf("%lld", result);
}