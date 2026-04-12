#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M, K;
ll mod = 1000000007;
ll F[200010] = {1}, R[200010];

ll pow_mod(ll a, ll b)
{
    if(b == 0)return 1;
    ll ret = pow_mod(a * a % mod, b / 2);
    if(b % 2)ret = ret * a % mod;
    return ret;
}

ll con(int a, int b)
{
    return F[a] * R[b] % mod * R[a - b] % mod;
}

ll unit(int n, int m, int k)
{
    ll ret = 0;
    for(int i = 1; i < n; i++)
    {
        ret += m * m % mod * (n - i) % mod * con(n * m - 2, k - 2) % mod * i % mod;
        ret %= mod;
    }

    return ret;
}

int main()
{
    cin >> N >> M >> K;

    for(int i = 1; i < 200010; i++)F[i] = F[i - 1] * i % mod;
    for(int i = 0; i < 200010; i++)R[i] = pow_mod(F[i], mod - 2);

    ll ans = (unit(N, M, K) + unit(M, N, K)) % mod;

    cout << ans << endl;
    return 0;
}
