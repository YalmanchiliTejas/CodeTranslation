/***************************************************

@author: vichitr
Compiled On: 19th Mar 2020

*****************************************************/
#include<bits/stdc++.h>
#define MAX 9223372036854775807
#define endl "\n"
#define ll long long
#define int long long
#define double long double
#define pb push_back
#define pf pop_front
#define mp make_pair
#define ip pair<int, int>
#define F first
#define S second

#define loop(i,n) for(int i=0;i<n;i++)
#define loops(i,s,n) for(int i=s;i<=n;i++)
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
using namespace std;

const ll MOD = 998244353;
const ll SZ = 107;
const ll N = 2e5+7;
// const ll M = 2e5+7;

ll pwr(ll x, ll y)
{
    ll r = 1LL;
    while(y)
    {
        if(y&1)
            r = (r * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return r;
}

int inv(int x)
{
    return pwr(x, MOD-2ll);
}

// int fact[N];

// int nCr(int x, int y){
//     int ans= fact[x];
//     ans *= inv(fact[y]);
//     ans %= MOD;
//     ans *= inv(fact[x-y]);
//     ans %= MOD;
//     return ans;
// }

// bool prim(int n){
//     for(int i=2;i*i<=n;i++){
//         if(n%i==0)
//             return 0;
//     }
//     return 1;
// }
bool ispal(string s){
    int n = s.size();
    for(int i=0;i<n/2;i++)
        if(s[i]!=s[n-1-i])
            return 0;
    return 1;
}

int dp[3005][3005], a[3005], n, S;

int solve(int idx, int s){
    if(s == 0)
        return (n-idx+1);
    if(idx >= n or s < 0)
        return 0;
    int &ans = dp[idx][s];
    if(ans != -1)
        return ans;
    ans = 0;
    if(s == S){
        ans += solve(idx+1, s);
        // if(idx==0) cout<<ans<<" ";
        ans %= MOD;
        ans += (idx+1)*solve(idx+1, s-a[idx]);
        ans %= MOD;
        // if(idx==0)cout<<ans<<endl;
    }
    else{
        ans += solve(idx+1, s);
        ans %= MOD;
        ans += solve(idx+1, s-a[idx]);
        ans %= MOD;
    }
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
    return ans;
}

void solve()
{ 
    // int s;
    cin>>n>>S;
    loop(i, n) cin>>a[i];
    int ans =0;
    memset(dp, -1, sizeof dp);
    ans = solve(0, S);
    cout<<ans;
}

signed main()
{
    fast;
// #ifndef ONLINE_JUDGE
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif
    int t=1;
    // cin >>t;

    // fact[0] =1;
    // for(int i=1;i<N;i++){
    //     fact[i] = fact[i-1]*i;
    //     fact[i] %= MOD;
    // }
    // int i  =1;
    while(t--){
        // int n = i++;
        solve();
        
    }
    return 0;
}

/*****************************

1
10 3
1 5 1
3 6 1
6 9 1


**************************/