#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

typedef long long ll;
const ll inf = 10000000000000000;
const int mx = 3010;
ll a[mx];
ll dp1[mx][mx];
ll dp2[mx][mx];

ll dfs1(int l, int r);
ll dfs2(int l, int r);

ll dfs1(int l, int r){
    if(l == r)return a[l];
    if(dp1[l][r] > -inf)return dp1[l][r];
    ll res = -inf;
    chmax<ll>(res, dfs2(l, r - 1) + a[r]);
    chmax<ll>(res, dfs2(l + 1, r) + a[l]);
    return dp1[l][r] = res;
}

ll dfs2(int l, int r){
    if(l == r)return -a[l];
    if(dp2[l][r] < inf)return dp2[l][r];
    ll res = inf;
    chmin<ll>(res, dfs1(l, r - 1) - a[r]);
    chmin<ll>(res, dfs1(l + 1, r) - a[l]);
    return dp2[l][r] = res;
}

int main(){
    
    int n; cin >> n;
    rep(i, n)cin >> a[i];

    rep(i, mx)rep(j, mx){
        dp1[i][j] = -inf;
        dp2[i][j] = inf;
    }

    cout << dfs1(0, n - 1) << endl;
    return 0;

}