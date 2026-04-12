#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

ll n;
ll a[3100];
ll dp[3100][3100], visit[3100][3100];
ll inf = 1LL<<60;
ll rec(ll L, ll R) {
    if (L > R) return 0;
    if (visit[L][R] == 1) return dp[L][R];
    visit[L][R] = 1;
    
    ll diff = n - (R - L + 1);

    ll res = 0;
    if (diff % 2 == 0) {
        res = -inf;
        chmax(res, rec(L+1, R) + a[L]);
        chmax(res, rec(L, R-1) + a[R]);
    } else {
        res = inf;
        chmin(res, rec(L+1, R) - a[L]);
        chmin(res, rec(L, R-1) - a[R]);
    }
    return dp[L][R] = res;
}

int main() {
    cin >> n;
    rep (i, n) cin >> a[i];
    cout << rec(0, n-1) << endl; 
}