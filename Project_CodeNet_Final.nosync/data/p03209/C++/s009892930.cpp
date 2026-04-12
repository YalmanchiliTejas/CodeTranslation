#include <bits/stdc++.h>

#define CEIL(a,b) ((a) / (b) + ((a) % (b) == 0 ? 0 : 1))
#define X first
#define Y second

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vl = vector<ll>;
using vs = vector<string>;

constexpr int MOD = int(1e9 + 7);
constexpr int INF = int(1e9 + 1);
constexpr ll LLINF = ll(4 * 1e18 + 1);
// constexpr int INF = 2147483647; // 2 * 1e9
// constexpr ll LLINF = 9223372036854775807; // 9 * 1e18

const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};

ll p[51] = {1};
ll a[51] = {1};

ll calc(int lv, ll x){
    if(x == 0) return 0;
    if(x == a[lv]) return p[lv];
    if(x >= (a[lv] + 1) / 2) return p[lv] - calc(lv - 1, a[lv] - x - 1);
    return calc(lv - 1, x - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);

    for(int i = 0; i < 50; ++i){
        p[i + 1] = 2 * p[i] + 1;
        a[i + 1] = 2 * a[i] + 3;
    }

    int n;
    ll x;
    cin >> n >> x;

    cout << calc(n, x) << "\n";
}
