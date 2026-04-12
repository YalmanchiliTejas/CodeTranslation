#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    ll ans = 0;
    rep(x, 1e4)
    {
        rep(i, N)
        {
            if (a[i] >= N)
            {
                ll del = a[i] / N;
                ans += del;
                a[i] -= del * N;
                rep(j, N) if (i != j) a[j] += del;
            }
        }
    }
    cout << ans << endl;
}