#include <bits/stdc++.h>
using namespace std;
using ll =  long long;
const ll INTF = 1e9 + 7;

int main() {

    string k;
    cin >> k ;

    int d;
    cin >> d;

    vector<vector<int>> dp(d, vector<int>(2));
    dp[0][0] = 1;
    for(int i=0; i<k.length(); i++)
    {
        vector<vector<int>> ndp(d, vector<int>(2));
        for(int j=0; j<d; j++)
        {
            for(int p=0; p<=1; p++)
            {
                for(int q=0; q<10; q++)
                {
                   if(q > k[i]-'0' && !p)
                    break;
                    ndp[(q+j)%d][p || q < k[i]-'0'] = (ndp[(q+j)%d][p || q < k[i]-'0'] + dp[j][p])%INTF;
                }
            }
        }
        dp = ndp; 
    }

    int ans = 0;
    ans = (dp[0][0] + dp[0][1])%INTF;

    --ans;
    if(ans<0)
        ans += INTF;

    cout<<ans;
    
    return 0;
}