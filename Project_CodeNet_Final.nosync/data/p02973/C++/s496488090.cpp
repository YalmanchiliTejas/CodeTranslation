//   __________________
//  | ________________ |
//  ||          ____  ||
//  ||   /\    |      ||
//  ||  /__\   |      ||
//  || /    \  |____  ||
//  ||________________||
//  |__________________|
//  \\#################\\
//   \\#################\\
//    \        ____       \
//     \_______\___\_______\
// An AC a day keeps the doctor away.

#pragma GCC optimize("Ofast")
#pragma loop_opt(on)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define debug(x) 0//(cerr<<#x<<" = "<<(x)<<'\n')
#define all(v) begin(v),end(v)
#define siz(v) (ll(v.size()))
#define get_pos(v,x) (lower_bound(all(v),x)-begin(v))
#define pb emplace_back
#define ff first
#define ss second
#define mid (l+(r-l>>1))
#define rep(i,n) for(int i = 0; i < (n); i++)
#define REP(i,n) for(int i = 1; i <= (n); i++)

using namespace std;
using namespace __gnu_pbds;
typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;
typedef pair<ll,ll> pll;
template <typename T> using rkt = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
constexpr ld PI = acos(-1), eps = 1e-8;
constexpr ll N = 50, INF = 1e18, MOD = 1000000007, K = 2;
constexpr inline ll cdiv(ll x, ll m) { return (x+m-1)/m; } // ceiling divide, x/m for flooring divide
template <typename T> void M(T &x, ll m = MOD){x%=m; if(x<0) x+=m;}

ll n,v;
multiset<ll> tails;
signed main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v;
        auto it = tails.lower_bound(v);
        if(it == tails.begin()) { // smallest, becomes a new head
            tails.insert(v);
        }else { // the best choice is to put it behind the nearest tail
            tails.erase(prev(it));
            tails.insert(v);
        }
    }
    cout << tails.size() << '\n';
}
