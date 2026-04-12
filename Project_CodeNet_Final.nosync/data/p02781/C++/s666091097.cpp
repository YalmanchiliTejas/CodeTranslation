#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
int dp[110][110][2];
int main()
{ 
    string s;
    cin >>s;
    int n = s.size();
    int K;
    cin >> K;
    dp[0][0][0] = 1;
    rep(i,n)rep(j,K+1)rep(k,2){
        int x = s[i]- '0';//いまのけた
        
        rep(d,10){
            int ni = i+1,nj = j,nk = k;
            if(!k && d > x )continue;
            if(d < x)nk = 1;
            if(d != 0)nj++;
            dp[ni][nj][nk] +=dp[i][j][k];
        
        }
    }
    cout << dp[n][K][0]+dp[n][K][1] << endl;


    return 0;
}   