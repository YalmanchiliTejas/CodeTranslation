#include <iostream>
#include <vector>
#include <string>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    string s;   cin >> s;
    int K;  cin >> K;
    int n = s.size(); 
    vector<int[4][2]>dp(n+1);   //dp[i][j][k]:=i桁目までで非0がj個k=0:nを超えない　
    dp[0][0][1] = 1;
    rep(i, n)   rep(j, 4)   rep(k, 2){
        int d = s[i] - '0';
        rep(nd, 10){
            int ni = i + 1, nj = j, nk = k;
            if(nd)  nj++;
            if(nj > K)  continue;
            if(k){
                if(nd > d)  continue;
                if(nd < d) nk = 0;
            }
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }
    cout << dp[n][K][0] + dp[n][K][1] << endl;
}
