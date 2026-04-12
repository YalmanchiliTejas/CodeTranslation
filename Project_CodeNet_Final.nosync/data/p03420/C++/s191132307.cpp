#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    int i, j;
    long long int cnt = 0;
    scanf("%d %d",&N, &K);

    for(j=K+1;j<=N;j++){
        int A = N/j; int B = max(N - (K + N/j*j) + 1,0);
        int chk = (j-K);
        cnt += chk * A + B;
    }

    printf("%lld",cnt - (K==0?N:0));

    return 0;
}
