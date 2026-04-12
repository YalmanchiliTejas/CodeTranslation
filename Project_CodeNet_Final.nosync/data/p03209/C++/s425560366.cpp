#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define per(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define INF 2e9
#define LINF 1e18
typedef long long ll;
typedef pair<int, int> P;

int n;
ll x;
vector<ll> a, p;

ll f(int i, ll j) {
    if (i == 0) {
        return 1;
    }

    if (j == 1) return 0;
    if (j <= 1+a[i-1]) return f(i-1, j-1);
    if (j == 2+a[i-1]) return 1+p[i-1];
    if (j <= 2*a[i-1]+2) return 1+p[i-1]+f(i-1, j-a[i-1]-2);
    else return 1+2*p[i-1];

}

int main() {
    cin >> n >> x;
    a.resize(n+1); p.resize(n+1);
    a[0] = 1; p[0] = 1;
    rep(i, n) {
        a[i+1] = 2*a[i]+3;
        p[i+1] = 2*p[i]+1;
    }

    ll ans = f(n, x);

    cout << ans << endl;

}