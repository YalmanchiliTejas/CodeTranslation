#include <bits/stdc++.h>
#define bear ryan
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define ends ' '
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll inf = 1e9;
const int maxn = 2e5 + 10;

ll n, a[maxn];
ll d[maxn][5], ans = 0;

ll f(int x, int y) {
    if(x > n)   return 0;
    ll& r = d[x][y];
    if(r == -1) {
        r = LLONG_MIN;
        for(int j = 0; j < y; ++j) {
            r = max(r, a[x + j] + f(x + j + 2, y - j));
        }
    }
    return r;
}

int main(void) {
    fastio;
    memset(d, -1, sizeof(d));
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    if(n % 2 == 0)  cout << f(1, 2);
    else            cout << f(1, 3);
    return 0;
}