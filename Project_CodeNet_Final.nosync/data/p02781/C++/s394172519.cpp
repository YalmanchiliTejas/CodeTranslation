#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int INF = 1<<30;
const long long LINF = 1LL<<60;

string n;
int k;
ll dp[101][4][2] = {};

void calc(int p){
    for(int i = 0; i < n.size(); i++){
        for(int j = 0; j <= k; j++){
            if(j < k){
                dp[i + 1][j][0] += dp[i][j][0];
                dp[i + 1][j + 1][0] += dp[i][j][0] * 9 + dp[i][j][1] * max(0, n[i] - '0' - 1);
                if(n[i] == '0'){
                    dp[i + 1][j][1] += dp[i][j][1];
                }else{
                    dp[i + 1][j][0] += dp[i][j][1];
                    dp[i + 1][j + 1][1] += dp[i][j][1];
                }
            }else{
                dp[i + 1][j][0] += dp[i][j][0];
                if(n[i] == '0'){
                    dp[i + 1][j][1] += dp[i][j][1];
                }else{
                    dp[i + 1][j][0] += dp[i][j][1];
                }
            }
        }
    }
}

int main(){
    cin >> n >> k;
    dp[0][0][1] = 1;
    calc(0);
    int m = n.size();
    ll ans = dp[m][k][0] + dp[m][k][1];
    cout << ans << endl;
    return 0;
}
