#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

int main(){

    long long d;
    string n;
    cin >> n >> d;
    
    //dp[i][j][k] := 左からi桁目,　桁和がj(mod D), flag, の時の数え上げdp
    vector<vector<vector<long long> > > dp(n.size() + 1, vector<vector<long long> > (d, vector<long long> (2, 0ll)));
    dp[0][0][0] = 1;
    for(int i = 0; i < n.size(); i++){
        for(int j = 0; j < d; j++){
            
            //cout << "( ";
            for(int k = 0; k < 2; k++){
                //cout << dp[i][j][k] << " ";

                int num = (int)(n[i] - '0');
                for(int l = 0; l <= 9; l++){
                    if(k == 0 && l <= num){
                        dp[i + 1][(j + l) % d][l != num] += dp[i][j][k];
                        dp[i + 1][(j + l) % d][l != num] %= MOD;               
                    }else if(k == 1){
                        dp[i + 1][(j + l) % d][k] += dp[i][j][k];
                        dp[i + 1][(j + l) % d][k] %= MOD;
                    }
                }
            }

            //cout << ") ";
        }
        //cout << endl;
    }


    //cout << endl;
    cout << (dp[n.size()][0][0] + dp[n.size()][0][1] - 1 + MOD) % MOD << endl;

    return 0;
}
