#include <bits/stdc++.h>
typedef long long ll;
#define fr first
#define sc second
#define int ll

using namespace std;
const int MN = 1e4+7;
const int MK = 1e2+7;
const int MOD = 1e9+7;

int d, dp[MN][MK];

signed main(){
    string s;
    cin >> s;
    cin >> d;
    /*if(d == 1){
        ll w = 0, x = 1;
        for(int i = s.size()-1; i >= 0; i--){
            w = (w + (s[i]-'0') * x) % MOD;
            x = (x * 10) % MOD;
        }
        cout << w;
        return 0;
    }*/
    dp[0][0] = 1;
    for(int j = 0; j < 10; j++){
        dp[1][j%d]++;
    }
    for(int i = 2; i < s.size()+3; i++){
        for(int j = 0; j < d; j++){
            for(int z = 0; z < 10; z++){
                dp[i][j] = (dp[i][j] + dp[i-1][(j-z+20*d)%d]) % MOD;
            }
        }
    }
    ll re = 0, f = 0;
    for(int i = 0; i < s.size(); i++){
        //cout << i << " :\n";
        for(int z = 0; z < s[i]-'0'; z++){
            //cout << z << ' ' << dp[s.size()-i-1][(d*20 - (f+z))%d] << " \n";
            re = (re + dp[s.size()-i-1][(d*20 - (f+z))%d]) % MOD;
        }
        f = (f + s[i]-'0') % d;
    }
    //cout << f << endl;
    if(f % d == 0)re++;
    cout << (re-1+MOD) % MOD;
}
