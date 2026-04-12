#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const int INF = 1000000007;
const ll INFLL = 1000000000000000007;

#define st first
#define nd second
#define pb push_back
#define _boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// ***************************** CODE ***************************** //

const int mod = 1e9 + 7;

void add(int& a, int b)
{
    a += b;
    if(a >= mod)
        a -= mod;
}

int main() {
    _boost;

    string k; int d;
    cin >> k >> d;
    int len = k.size();

    vector <vector<int>> dp(d, vector<int>(2));
    dp[0][0] = 1;
    for(int i = 0; i < len; i++)
    {
        vector <vector<int>> new_dp(d, vector<int>(2));
        for(int sum = 0; sum < d; sum++)
        {
            for(int j = 0; j < 2; j++)
            {
                for(int digit = 0; digit < 10; digit++)
                {
                    if(digit > k[i]-'0' && j == 0)
                        break;
                    if(j == 1 || digit < k[i]-'0')
                        add(new_dp[(sum+digit)%d][1], dp[sum][j]);
                    else
                        add(new_dp[(sum+digit)%d][0], dp[sum][j]);
                }
            }
        }
        dp = new_dp;
    }
    int ans = (dp[0][0] + dp[0][1]) % mod;
    ans--;
    if(ans <= -1)
        ans = mod - 1;
    cout << ans;


    return 0;
}
