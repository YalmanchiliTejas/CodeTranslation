#include<bits/stdc++.h>
using namespace std;

#define y1 as214
#define ii pair < int , ll >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define fr front()
#define pb push_back
#define t top()

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)

#define ll long long
#define oo INT_MAX
#define int long long

ll n , mod = 1e9 + 7;
ll dp[100005][105];
string s;
vector < int > digit;

ll getdigit(int idx , int sum , int tight)
{
    if(idx == -1)
        return (sum == 0);
    if(tight == 0 && dp[idx][sum] != -1)
        return dp[idx][sum];
    int lim = (tight == 0) ? 9 : digit[idx];
    ll ret = 0;
    FOR(k , 0 , lim)
        ret = (ret + getdigit(idx - 1 , (sum + k) % n , tight & (digit[idx] == k))) % mod;
    if(tight == 0)
        dp[idx][sum] = ret;
    return ret;
}

main()
{
    //freopen("S.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    getline(cin , s);
    memset(dp , -1 , sizeof(dp));
    for(int i = s.size() - 1 ; i >= 0 ; i--)
        if(s[i] >= 48 && s[i] <= 57)
            digit.pb(s[i] - 48);
    cin >> n;
    int x = getdigit(digit.size() - 1 , 0 , 1) - 1;
    if(x < 0)
        cout << x + mod;
    else
        cout << x;
}
