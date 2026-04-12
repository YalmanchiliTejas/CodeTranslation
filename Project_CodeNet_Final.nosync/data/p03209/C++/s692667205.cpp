#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;

ll a(ll L) {  // a(i) : レベルiバーガーの厚さ
    if(L == 0) {
        return 1;
    }
    return 2*a(L-1) + 3;
}

ll f(ll L, ll x) {  // レベルLバーガーの下からx層に含まれるパティの枚数
    if(L == 0) {
        return 1;
    }
    else if(x == 1) {
        return 0;
    }
    else if(x <= 1 + a(L-1)) {
        return f(L-1, x-1);
    }
    else if(x == 2 + a(L-1)) {
        return f(L-1, a(L-1)) + 1;
    }
    else if(x <= 2 + 2*a(L-1)) {
        return f(L-1, x - (2 + a(L-1))) + f(L-1, a(L-1)) + 1;
    }
    else if(x == 3 + 2*a(L-1)) {
        return 2*f(L-1, a(L-1)) + 1;
    }
}
 
int main() {
    ll n, x;
    cin >> n >> x;
    
    out(f(n, x));
    re0;
}