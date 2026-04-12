#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll dp[105][5][2];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    dp[0][0][0] = 1;
    rep(i,n)rep(j,4)rep(l,2){
        int nd = s[i] - '0';
        rep(d,10){
            int ni = i+1, nj = j, nl = l;
            if(d != 0) nj++;
            if(nj > k) continue;
            if(l == 0){
                if(d > nd) continue;
                if(d < nd) nl = 1;
            }
            dp[ni][nj][nl] += dp[i][j][l];
        }
    }
    ll ans = dp[n][k][0] + dp[n][k][1];
    cout << ans << endl;
    return 0;
}