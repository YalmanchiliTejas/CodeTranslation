#include <bits/stdc++.h>

using namespace std;
const int N = 1e4+5;
const int MOD = 1e9+7;
void add(int &a, int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
}
int main()
{
    string k;
    int d;
    cin >> k >> d;
    int n = k.length();
    vector< vector<int> > dp(d,vector<int>(2));
    dp[0][0] = 1;
    for (int i = 0; i<n; i++)
    {
        vector< vector<int> > new_dp(d,vector<int>(2));
        for (int sum = 0; sum<d; sum++)
            for (bool took: {false, true})
                for (int digit = 0; digit<10; digit++){
                    if (digit>k[i]-'0' && !took)
                        break;
                    bool t = (took || digit<k[i]-'0');
                    add(new_dp[(sum+digit)%d][t],dp[sum][took]);
                }
        dp = new_dp;
    }
    cout << ((dp[0][0]+dp[0][1])%MOD-1+MOD)%MOD;
}
