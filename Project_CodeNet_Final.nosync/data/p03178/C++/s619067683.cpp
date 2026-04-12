#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ull unsigned long long
#define mp make_pair
#define F first
#define S second
#define mod 1000000007



int main()
{
    string s;
    cin >> s;
    int d;
    cin >> d;
    vector<vector<int> > dp(d, vector<int>(2));
    
    dp[0][0] = 1;
    for(int i=0; i<s.size();i++)
    {
        vector<vector<int> > tmp_dp(d, vector<int>(2));
        int cur = s[i]-'0';
        for(int remainder=0; remainder<d; remainder++)
        {
            bool ar[2];
            ar[0] = false;
            ar[1] = true;
            for(bool small:ar) 
                for(int j=0;j<10;j++)
                {
                    if(j > cur && !small)
                    {
                        break;
                    }
                    tmp_dp[(remainder+j)%d][small || j<cur] = (tmp_dp[(remainder+j)%d][small || j<cur]
                                            + dp[remainder][small])%mod ;
                }
        }
        dp = tmp_dp;
    }

    int ans = (dp[0][true] + dp[0][false])%mod;
    ans--;
    if(ans<0)
        ans = mod-1;
    
    cout << ans << endl;

}
