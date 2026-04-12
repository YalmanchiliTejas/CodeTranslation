#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1000000007;
int main()
{
    int N;
    cin >> N;
    ll A[N];
    ll sum = 0LL;
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
        sum += A[i];
        sum %= mod;
        sum = (sum + mod) % mod;
    }
    ll ans = 0LL;
    for (int i = 0; i < N; i++)
    {
        sum -= A[i];
        sum = (sum + mod) % mod;
        ans += A[i] * sum % mod;
    }
    ans %= mod;
    cout << ans << endl;
}