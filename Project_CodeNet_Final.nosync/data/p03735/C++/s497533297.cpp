#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define ld          long double
#define x           first
#define y           second
#define mp          make_pair

using namespace std;

const int N = int(2e5) + 7;
const int inf = int(1e9) + 7;
typedef pair<int, int> pii;

int n, rmax, rmin, bmax, bmin;
ll res1, res2;
pii p[N];

void Maximize(int& x, int y) {if(x < y) x = y;}
void Minimize(int& x, int y) {if(x > y) x = y;}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n; rmax = bmax = -inf, rmin = bmin = inf;
    for(int i = 1; i <= n; ++i) {
        cin >> p[i].x >> p[i].y;
        if(p[i].x > p[i].y) swap(p[i].x, p[i].y);
        Maximize(rmax, p[i].x), Minimize(rmin, p[i].x);
        Maximize(bmax, p[i].y), Minimize(bmin, p[i].y);
    }
    res1 = 1ll * (rmax - rmin) * (bmax - bmin);
    sort(p + 1, p + n + 1);
    res2 = INT_MAX, rmax = bmin = p[1].y;
    for(int i = 2; i < n; ++i) {
        Maximize(rmax, p[i].y), Minimize(bmin, p[i].y);
        res2 = min(res2, (ll)(max(rmax, p[n].x) - min(bmin, p[i + 1].x)));
    }
    res2 *= (bmax - rmin);
    cout << min(res1, res2);
}
