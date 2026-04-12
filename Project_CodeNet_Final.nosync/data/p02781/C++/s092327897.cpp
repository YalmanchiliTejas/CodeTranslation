#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
int dp[110][2][110];
signed main(){
    string s;cin >> s;
    int K;
    cin >> K;
    int n = s.size();
    dp[0][0][0] = 1;
    rep(i,n)rep(j,2)rep(k,4){
        int d = s[i] - '0';
        rep(a,10){
            int ni = i+1,nj = j,nk = k;
            if(j == 0 && a > d)continue;
            if(nk > K)continue;
            if(a < d)nj = 1;
            if(a != 0)nk++;
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }
    int ans = dp[n][0][K] + dp[n][1][K];
    cout << ans << endl;

    return 0;
}