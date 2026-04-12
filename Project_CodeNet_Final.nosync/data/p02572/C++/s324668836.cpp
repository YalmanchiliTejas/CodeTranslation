#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()

int main()
{
    ll mod = 1000000007;
    ll ans = 0, k = 0;
    int N;
    cin >> N;
    v<ll> A(N), B(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        B[i + 1] = B[i] + A[i];
    }

    for (int i = 0; i < N; i++)
    {
        k = A[i] * ((B[N] - B[i + 1])%mod);
        ans += k;
        ans = ans % mod;
    }

    cout << ans << endl;
    return 0;
}