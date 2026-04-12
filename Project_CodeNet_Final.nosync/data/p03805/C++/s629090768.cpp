#pragma GCC optimize("Ofast")
  
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <list>
#include <tuple>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <numeric>
#include <math.h>
#include <bitset>
#include <random>
#include <regex>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,f,n) for(int i=f;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define Fixed fixed << setprecision(14)
#define int long long
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int mod1 = 1e9+7; 
constexpr int mod2 = 998244353;
constexpr int dy[] = {0,1,0,-1,1,-1,-1,1};
constexpr int dx[] = {1,0,-1,0,1,1,-1,-1};
 
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }

template <class A, class B> inline A updiv(const A a,const B b){ return (a + b - 1) / b; }
template <class A, class B> inline A gcd(const A a,const B b){ return b ? gcd(b,a % b) : a; }
template <class A, class B> inline A lcm(const A a,const B b){ return a / gcd(a,b) * b; }

template <class T> using min_heap = priority_queue<T,vector<T>,greater<T> >;
template <class T> using max_heap = priority_queue<T>;
template <class A,class B> using umap = unordered_map<A,B>;



signed main(void){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > dp(1 << n, vector<int>(n));
    vector<vector<bool> > g(n, vector<bool>(n));

    rep(i,m){
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a][b] = true;
        g[b][a] = true;
    }

    dp[1][0] = 1;

    rep(bit, 1 << n){
        rep(i, n){
            rep(j, n){
                if(i != j && (bit & 1 << j) == 0 && bit & 1 << i && g[i][j]){
                    dp[bit | 1 << j][j] += dp[bit][i];
                }
            }
        }
    }

    int res = 0;

    for(int i = 1; i < n; ++i){
        res += dp[(1 << n) - 1][i];
    }

    cout << res << '\n';

    return 0;
}