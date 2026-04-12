#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i = a; i < b;i++)
#define pb push_back
typedef long long ll;
int mod = 1e9 + 7;

void add_self(int &a, int b)
{
    a += b;
    if(a >= mod) a-= mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string k;
    int d;
    cin >> k;
    cin >> d;
    int n = k.length();
    //n++;
    vector<vector<int>> dp (d, vector<int>(2));
    //memset(dp,0,sizeof(dp));
    //reverse(k.begin(), k.end());
    dp[0][0] = 1;
    //dp[0][0][1] = 1;

    fo(i,0,n)
    {
        vector<vector<int>> new_dp (d,vector<int>(2));
        fo(j,0,d)
        {
            for(bool l : {false, true})
            {
                fo(dig,0,10)
                {
                    if(dig > k[i]-'0' && !l) break;
                    add_self(new_dp[(j+dig)%d][l || (dig < k[i] - '0')], dp[j][l]);
                    //cout << dp[i][j][l] << endl;
                }
                //cout << dp[i][j][l] << endl;
            }
        }
        dp = new_dp;
    }

    int res = (dp[0][false] + dp[0][true]) % mod;
    --res;
    if(res == -1) res += mod;
    cout << res << endl;
    return 0;
}
