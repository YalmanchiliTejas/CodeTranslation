#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e4 + 7;
int dp[N][103][2];
const int MOD = 1e9 + 7;
#define pb push_back

int recur(int id, string n, int k, int flg, int sum, vector<int> res)
{
    if(id == n.length())
    {
        if(sum == 0)
        {
            // for(auto i : res)
            //     cout << i;
            // cout << "\n";
            return 1;
        }
        return 0;
    }

    if(dp[id][sum][flg] != -1)
    {
        //cout << id << " " << sum << " " << flg << "\n";
        return dp[id][sum][flg] % MOD;
    }

    int ans = 0;

    if(flg)
    {
        int j = n[id] - '0';

        for(int i = 0; i <= j; i++)
        {
            if(i == j)
            {
                //res.pb(i);
                ans = (ans + recur(id + 1, n, k, 1, (sum + i) % k, res)) ;
                //res.pop_back();
            }
            else
            {
                //res.pb(i);
                ans = (ans + recur(id + 1, n, k, 0, (sum + i) % k, res)) ;
                //res.pop_back();
            }
        }
    }
    else
    {
        for(int i = 0; i <= 9; i++)
        {
            //res.pb(i);
            ans = (ans + recur(id + 1, n, k, 0, (sum + i) % k, res)) ;
            //res.pop_back();
        }
    }

    return dp[id][sum][flg] = ans % MOD;
}

int32_t main()
{
    string n;
    cin >> n;
    int k;
    cin >> k;
    
    memset(dp, -1, sizeof(dp));
    vector <int> v;
    cout << (recur(0, n, k, 1, 0, v) - 1 + MOD) % MOD<< "\n";
}
