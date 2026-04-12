#include <cmath>
#include <chrono>
#include <random>
#include <ctime>
#include <algorithm>
#include <iosfwd>
#include <iostream>
#include <list>
#include <ostream>
#include <streambuf>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define fori(i, n) for(ll i = 0; i < (n); ++i)
#define forI(i, n) for(ll i = 1; i <= (n); ++i)
#define pll pair<ll, ll>
#define ff first
#define ss second

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#define pt pair<ll, ll>
#define x first
#define y second

pll operator+ (pll a, pll b){ return {a.x + b.x, a.y + b.y}; }

ll rand0m() {
    return (ull(rand()) << 15ull | ull(rand()));
}                   //[0 ... n)
ll rand0m(ll x) {
    return rand0m() % x;
}               //[0 ... n)
ll rand0m(ll minn, ll maxx) {
    return rand0m(maxx - minn + 1) + minn;
}   //[minn ... maxx]

const ll MAXN = 1e5 + 1;
const ll mod = 1e9 + 7;
const ll INF = 2e9 + 1000;

ll n, m;
ll dp[3010][3010];
ll a[3010];

void solve(){
    cin >> n;
    fori(i, n) cin >> a[i];
    bool first = n % 2 == 1;
    forI(len, n){
        if(first)
            fori(i, n){
                if(i + len - 1 < n) dp[i][len] = dp[i][len - 1] + a[i + len - 1];
                if(i + 1 < n && (i + len - 1 >= n || dp[i][len] < dp[i + 1][len - 1] + a[i])) dp[i][len] = dp[i + 1][len - 1] + a[i];
            }
        else
            fori(i, n){
                if(i + len - 1 < n) dp[i][len] = dp[i][len - 1] - a[i + len - 1];
                if(i + 1 < n && (i + len - 1 >= n || dp[i][len] > dp[i + 1][len - 1] - a[i])) dp[i][len] = dp[i + 1][len - 1] - a[i];
            }
        first = !first;
    }
    cout << dp[0][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //stress();
    solve();
}