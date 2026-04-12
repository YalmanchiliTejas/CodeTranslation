#include <bits/stdc++.h>
#define REP(i,s,e) for(int i=(s); i<(e);i++)
#define rep(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n)
#define repe(i,n) for(auto &&i:n)
#define all(v) (v).begin(),(v).end()
#define decimal fixed<<setprecision(20)
#define fastcin() cin.tie(0);ios::sync_with_stdio(false)
using namespace std;
using LL = long long;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1e9;
const LL LLINF = 1e16;

LL dp[3340][3340][2];
int n;
vector<int> a;

LL rec(int l, int r, int turn){
    if(dp[l][r][turn] != -LLINF) return dp[l][r][turn];
    if(l+r == n) return dp[l][r][turn] = 0;
    if(turn == 0){
        LL tmp = -LLINF;
        chmax(tmp, rec(l+1, r, 1)+a[l]);
        chmax(tmp, rec(l, r+1, 1)+a[n-1-r]);
        return dp[l][r][turn] = tmp;
    }else{
        LL tmp = LLINF;
        chmin(tmp, rec(l+1, r, 0)-a[l]);
        chmin(tmp, rec(l, r+1, 0)-a[n-1-r]);
        return dp[l][r][turn] = tmp;
    }
}

int main(){
    fastcin();

    cin >> n;
    a.assign(n, 0);
    rep(i, n) cin >> a[i];
    fill(dp[0][0], dp[3340][0], -LLINF);
    cout << rec(0, 0, 0) << endl;


}