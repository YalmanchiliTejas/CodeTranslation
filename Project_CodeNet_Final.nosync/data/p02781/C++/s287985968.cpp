#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;

int dp[110][4][2];
signed main()
{
    string s;cin >> s;
    int K;
    cin >> K;
    int n = s.size();
    dp[0][0][0] = 1;
    rep(i,n)rep(j,4)rep(k,2){
        int d = s[i] - '0';
        rep(a,10){
            int ni = i+1,nj = j,nk = k;
            if(k == 0&& d < a)continue;
            if(j == 3 && a !=0)continue;
            if(j < 3 && a!=0)nj++;
            if(a < d)nk = 1;
            dp[ni][nj][nk] += dp[i][j][k];

            
        }

        
    }
    cout << dp[n][K][0] + dp[n][K][1] << endl;


    return 0;
}