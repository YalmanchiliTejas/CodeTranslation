#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
using vvv= vector<vv>;

int main(){
    string s;int k;
    cin>>s>>k;
    vvv dp(s.size()+1, vv (2, vi (k+2,0)));
    //less 1:ちょうど 0: たりない
    for(int i=0; i<s.size(); i++){
        if(!i){
            dp[i][1][1] = 1;
            dp[i][0][1] = s[0]-'1';
            dp[i][0][0] = 1;
        }
        else{
            if(s[i]=='0'){
                rep(dk,k+1){
                    dp[i][1][dk]   += dp[i-1][1][dk];
                    dp[i][0][dk+1] += dp[i-1][0][dk]*9;
                    dp[i][0][dk]   += dp[i-1][0][dk];
                }
            }
            else{
                rep(dk,k+1){
                    dp[i][1][dk+1] += dp[i-1][1][dk];
                    dp[i][0][dk+1] += dp[i-1][1][dk]*(s[i]-'1');
                    dp[i][0][dk]   += dp[i-1][1][dk];
                    dp[i][0][dk+1] += dp[i-1][0][dk]*9;
                    dp[i][0][dk]   += dp[i-1][0][dk];
                }
            }
        }
    }
    cout << dp[s.size()-1][0][k]+dp[s.size()-1][1][k] << endl;
    return 0;
}