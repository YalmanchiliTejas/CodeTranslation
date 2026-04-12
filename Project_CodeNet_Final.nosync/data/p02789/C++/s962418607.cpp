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
//     vector<int> par;
    
//     UnionFind(int N): par(N) {
//         for (int i=0;i<N;i++) par[i] = i;
//     }

//     int root(int x) {
//         if (par[x] == x) return x;
//         else return par[x] = root(par[x]);
//     }

//     void unite(int x, int y) {
//         int rx = root(x);
//         int ry = root(y);
//         if (rx == ry) return;
//         par[rx] = ry;
//     }

//     bool same(int x, int y) {
//         int rx = root(x);
//         int ry = root(y);
//         return rx == ry;
//     }
// };

int main(void) {
    int N, M;
    cin >> N >> M;
    if (N == M) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
