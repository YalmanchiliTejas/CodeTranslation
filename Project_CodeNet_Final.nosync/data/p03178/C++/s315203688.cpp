#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define sz(x) ((int)x.size())

int d;
vector<vector<int>> dp(100005, vector<int>(101, -1));
const int mod = 1000*1000*1000 + 7;

int digitDP(int index, int rem, int fit, string &number)
{
    if(index == -1)
        return (rem == 0) ? 1 : 0;
    if(!fit && dp[index][rem] != -1)
        return dp[index][rem];
    int limit = (fit) ? (number[index]-'0') : 9, cnt = 0;
    for(int i = 0; i <= limit; i++)
    {
        int newFit = (fit && (i == limit)) ? 1 : 0;
        cnt += digitDP(index-1, (rem-i+1000*d)%d, newFit, number);
        cnt %= mod;
    }
    if(!fit)
        dp[index][rem] = cnt;
    return cnt;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string k;
    cin >> k;
    reverse(k.begin(), k.end());
    cin >> d;
    cout << (digitDP(sz(k)-1, 0, 1, k) - 1 + mod)%mod << endl;
}