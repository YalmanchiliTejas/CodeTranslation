#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

typedef long long ll;
// constexpr ll MOD = 998244353;
constexpr ll MOD = 1000000007;

// struct UnionFind {
//     vector<ll> par;
//     vector<ll> siz;
    
//     UnionFind(ll N): par(N), siz(N,1LL) {
//         for (ll i=0;i<N;i++) par[i] = i;
//     }

//     ll root(ll x) {
//         if (par[x] == x) return x;
//         else return par[x] = root(par[x]);
//     }

//     void unite(ll x, ll y) {
//         ll rx = root(x);
//         ll ry = root(y);
//         if (rx == ry) return;
//         par[rx] = ry;
//         siz[ry] += siz[rx];
//     }

//     bool same(ll x, ll y) {
//         ll rx = root(x);
//         ll ry = root(y);
//         return rx == ry;
//     }

//     ll size(ll x) {
//         return siz[root(x)];
//     }
// };

int N;
vector<vector<int>> E(10);
vector<bool> V(10,false);
int dfs(int s, int d) {
    if (V[s]) return 0;
    if (d == N-1) return 1;
    int res = 0;
    V[s] = true;
    for (auto i: E[s]) {
        if (!V[i]) res += dfs(i,d+1);
    }
    V[s] = false;
    return res;
}

int main(void) {
    int M;
    cin >> N >> M;
    vector<int> a(30), b(30);
    for (int i=0;i<M;i++) cin >> a[i] >> b[i];
    // set<pair<int,int>> E;
    // for (int i=0;i<M;i++) {
    //     E.emplace(a[i],b[i]);
    // }
    for (int i=0;i<M;i++) {
        E[a[i]].push_back(b[i]);
        E[b[i]].push_back(a[i]);
    }

    cout << dfs(1,0) << endl;

    return 0;
}
