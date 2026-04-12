#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long ipow(long long a, long long b)
{
    if(b==0) return 1;
    long long ans = ipow(a, b/2);
    ans = ans*ans%MOD;
    if(b%2==1) ans=ans*a%MOD;
    return ans;
}
long long fact(int N)
{
    long long ret = 1;
    for(int i=1; i<=N; ++i) ret=ret*i%MOD;
    return ret;
}
int solve(int N)
{
    long long ans = ipow(3, N);

    long long nCk = fact(N)*ipow(fact(N/2), 2*(MOD-2))%MOD;;
    for(int k=N/2+1; k<=N; ++k)
    {
        nCk = nCk * ipow(k, MOD-2)%MOD*(N-k+1)%MOD;
        ans -= 2*nCk*ipow(2, N-k);
        ans %= MOD;
        ans += MOD;
        ans %= MOD;
    }
    return ans;
}

int main()
{
    int N; scanf("%d", &N);
    printf("%d\n", solve(N));
}