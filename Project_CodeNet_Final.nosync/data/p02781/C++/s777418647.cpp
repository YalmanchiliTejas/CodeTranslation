#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

ll dp[110][10][2];
int main(void){
    string n;
    ll k;

    cin >> n >> k;
    ll len = n.size();
    dp[0][1][0] = 1;
    dp[0][1][1] = ll(n[0]) - ll('0') - 1;
    dp[0][0][1] = 1;

    rep(i, 1, len){
        rep(j, 0, k + 1){
            //未満フラグ0 →0の場合
            if(n[i] == '0'){
                dp[i][j][0] += dp[i - 1][j][0];
            }else{
                if(j != 0){
                    dp[i][j][0] += dp[i - 1][j - 1][0];
                }
            }


            //未満フラグ1 →1の場合
            //0の場合
            dp[i][j][1] += dp[i - 1][j][1];

            //0でない値を入れる場合
            if(j != 0){
                dp[i][j][1] += dp[i - 1][j - 1][1] * 9;
            }

            //未満フラグ0 →1の場合
            if(j != 0){
                if(n[i] != '0'){
                    //0の場合
                    dp[i][j][1] += dp[i - 1][j][0];
                    //0でない値を入れる場合
                    dp[i][j][1] += dp[i - 1][j - 1][0] * (ll((n[i])) - ll('0') - 1);
                }
            }
        }
    }

    cout << dp[len - 1][k][1] + dp[len - 1][k][0] << endl;

}
