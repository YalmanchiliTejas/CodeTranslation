// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using vii = vector<int>;
using pii = pair<int, int>;
template <typename T = vii> 
using vec = vector<T>;

const ll INF = 1e18, MOD = 1e9 + 7;

const int MAX = 1e6;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    // freopen("in.in", "r", stdin);
    
    int n;
    cin >> n;
    vec<pii> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    vii res(n);
    const int m = n / 2;
    for (int i = 0; i < n; i++) {
        res[v[i].second] = v[m - (m <= i)].first;
    }
    for (int e : res) {
        cout << e << '\n';
    }
}