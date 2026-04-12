#include <bits/stdc++.h>
#define ll long long
#define eps 1e-9
#define PI 2 * acos (0.0)
using namespace std;

const int mod = 1000000000 + 7;



// inverse mod of i%prime = bigmod(i,prime-2)
long long bigmod(long long a, long long n) {
    n %= mod - 1;
    long long res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a;
            if (res >= mod) {
                res %= mod;
            }
        }
        a = a * a;
        if (a >= mod) {
            a %= mod;
        }
        n >>= 1;
    }
    return res;
}

ll ncr[1001][1001];
ll fct[1001];
ll dp[1001];
bool bi[1001];

void computeNCR()
{
    fct[0] = fct[1] = 1;
    for(int i = 0; i <= 1000; i++)
    {
        ncr[i][1] = i;
    }
    for(int n = 2; n <= 1000; n++)
    {
        fct[n] = (fct[n - 1] * n) % mod;
        for(int r = 2; r <= n; r++)
        {
            ncr[n][r] = ( ncr[n - 1][r - 1] + ncr[n - 1][r] ) % mod;
        }
    }
}

ll computeNSK(int N, int S, int K)
{
    ll ans = 1;
    for(int i = 0; i < K; i++)
    {
        ans = (ans * ncr[N - i * S][S]) % mod;
    }
    ans = (ans * bigmod(fct[K], mod - 2) ) % mod;

    return ans;
}



int main()
{

   

    computeNCR();

    int a, b, c, d, e, x, y, z;

    int N, A, B, C, D;

    cin>>N>>A>>B>>C>>D;

    for(int i = A; i <= B; i++) // group size
    {
        for(int j = N - C * i; j >= 1; j--)
        {
            if(bi[j])
            {
                for(int k = C; k <= D; k++)
                {
                    if(j + i * k > N)
                    {
                        break;
                    }
                    bi[j + i * k] = true;
                    dp[j + i * k] = (dp[j + i * k] + (dp[j] * computeNSK(N - j, i, k)) %mod ) % mod;
                }
            }
        }
        for(int k = C; k <= D; k++)
        {
            if(i * k > N)
            {
                break;
            }
            bi[i * k] = true;
            dp[i * k] = (dp[i * k] + computeNSK(N, i, k)) % mod;
        }
    }

    cout<<dp[N]<<endl;
	
    return 0;
}
