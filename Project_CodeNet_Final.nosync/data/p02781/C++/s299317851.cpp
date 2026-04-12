#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int dp[105][4][2];

int main(){
    string s; cin >> s;
    int n = s.size();
    int K; cin >> K;
    dp[0][0][0] = 1;
    rep(i,n)rep(j,4)rep(k,2){
        //nd : 今見ている桁の数字(i+1桁目)
        int nd = s[i]-'0';
        rep(d,10){
            int ni = i+1, nj = j, nk = k;
            if(d != 0) nj++;//非0を一つ使った
            if(nj > K) continue;//非0の個数が条件よりも多い
            if(k == 0){
                //i桁目までの桁はNと一致
                if(d > nd) continue;
                if(d < nd) nk = 1;
            }
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }
    int ans = dp[n][K][0] + dp[n][K][1];
    cout << ans << endl;
    return 0;
}