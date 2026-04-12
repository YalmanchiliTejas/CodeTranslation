#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <cstdint>
#include <cctype>
#include <numeric>
#include <bitset>
#include <functional>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;
using Pii = pair<int, int>;

constexpr int INF = 1 << 30;
constexpr ll LINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr long double EPS = 1e-10;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll n, x, m;
    cin >> n >> x >> m;

    vector<ll> v;
    v.push_back(0);
    vector<bool> used(m, false);
    ll a = x;
    v.push_back(x);
    used[a] = true;
    int loop_start = 0;
    for(int i=2;i<=2*m;++i) {
        a = (a * a) % m;
        if(used[a]) {
            break;
        }
        v.push_back(a);
        used[a] = true;
    }
    for(int j=1;j<v.size();++j) {
        if(a == v[j]) {
            loop_start = j;
            break;
        }
    }

    int nv = v.size();
    for(int i=1;i<nv;++i) {
        v[i] += v[i-1];
    }
    
    if(n < nv) {
        cout << v[n] << endl;
        return 0;
    }

    ll ans = v[nv-1];
    n -= nv-1;
    ans += (v[nv-1] - v[loop_start-1]) * (n / (nv - loop_start));
    n %= (nv - loop_start);
    ans += (v[loop_start-1 + n] - v[loop_start-1]);

    cout << ans << endl;
}
