#include<bits/stdc++.h>
using namespace std;
#define int long long
//#undef int
#define mk make_pair
#define pb push_back
typedef pair<int, int> pii;
const int mod = 1000000007;
const int INF = 1000000009;
const long long INFL = 1000000000000000018ll;

string s;
int D, N;
int dp[11000][110][2];

int dfs(int k = -1, int sum = 0, bool flag = false)
{
    int mem;
    if(flag)mem = 1;
    else mem = 0;
    if(k == -1){
        int res = 0;
        for(int i = 0; i <= s[k + 1] - '0'; i++){
            res += dfs(k + 1, (sum + i) % D, i == s[k + 1] - '0');
            res %= mod;
        }
        return res % mod;
    }
    if(~dp[k][sum][mem]){
        return dp[k][sum][mem] % mod;
    }
    if(k == N - 1){
        if(sum % D == 0){
            //printf("%lld %lld %lld\n", k, sum, mem);
            return dp[k][sum][mem] = 1;
        }
        else {
            return dp[k][sum][mem] = 0;
        }
    }
    if(flag){
        int res = 0;
        for(int i = 0; i <= s[k + 1] - '0'; i++){
            res += dfs(k + 1, (sum + i) % D, i == s[k + 1] - '0');
            res %= mod;
        }
        return dp[k][sum][mem] = res % mod;
    }
    else {
        int res = 0;
        for(int i = 0; i <= 9; i++){
            res += dfs(k + 1, (sum + i) % D, false);
            res %= mod;
        }
        return dp[k][sum][mem] = res % mod;
    }
}

signed main()
{
    cin >> s;
    cin >> D;
    N = s.size();
    memset(dp, -1, sizeof(dp));

    cout << (dfs() - 1 + mod) % mod << endl;

    return 0;
}
/*



*/


