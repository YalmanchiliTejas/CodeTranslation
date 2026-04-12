#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MOD 1000000007

long long int dp[3005][3005];

int main(){
    rep(i,3005) rep(j,3005)  dp[i][j] = 0;
    int n; cin >> n;
    vector<long long int> a(n); rep(i,n) cin >> a[i];
    rep(i,n){
        for(int j=0;j+i<n;j++){
            int len = i + 1;
            bool turn = ((n - len)   % 2 == 0);
            
            if(len == 1){
                if(turn) dp[j][j+i] = a[j];
                else dp[j][j+i] = -a[j];
            }else if (turn){
                dp[j][j+i] = max(a[j] + dp[j+1][j+i], a[j+i] + dp[j][j+i-1]);
            }else{
                dp[j][j+i] = min(-a[j] + dp[j+1][j+i], -a[j+i] + dp[j][j+i-1]);
            }  
            //cout << j <<  ":" << i+j << ":" << dp[j][i+j] <<  endl;
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}