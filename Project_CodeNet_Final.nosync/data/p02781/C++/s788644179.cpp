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

ll binom(ll n, ll k) {
    ll res = 1;
    if (n<k) return 0;
    for (int i=max(n-k,k)+1;i<=n;i++) res *= i;
    for (int i=min(n-k,k);i>0;i--) res /= i;
    return res;
}

int main(void) {
    string N;
    int K, c[4] = {1,9,81,729};
    cin >> N >> K;
    ll res = 0;
    int L = N.size();
    for (int i=K;i<L;i++) {
        res += c[K]*binom(i-1,i-K);
        // printf("%d-digit: %d\n",i,res);
    }
    int m = 0;
    for (int i=1;i<=L;i++) {
        // if (N[i-1] != '0') m++;
        if (i>1 && N[i-1] > '0') res += c[K-m]*((K>m)?binom(L-i,K-m):1);
        if (N[i-1] != '0') m++;
        for (int j=1;j<(N[i-1]-'0');j++) res += c[K-m]*((K>m)?binom(L-i,K-m):1);
        if (m == K) {
            res++;
            break;
        }
        // printf("%d-digit; %d-digit: %d\n",L,i,res);
    }
    cout << res << endl;

    return 0;
}
