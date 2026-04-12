
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pt;
typedef pair<ll,ll> pll;

#define Max 1000001
#define intinf 2147483647
#define longlonginf 9223372036854775807
#define MOD 998244353
#define MOD2 1000000007
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vint vector<int>
#define vll vector<long long>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define F(i,n) for(int i = 0;i<n;i++)
#define Fr(i,l,r) for(int i = l;i <= r;i++)
#define rF(i,n) for(int i = n-1;i>=0;i--)
#define all(arr) arr.begin(),arr.end()


ll Lpow(ll a,ll b)
{
    ll ans = 1;
    while(b > 0)
    {
        if(b%2)
            ans = (ans*a);
        a = (a*a);
        b = b/2;
    }
    return ans;
}

ll gcd(ll a,ll b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}

ll dp[3005][3005];
ll arr[3005];

ll recur(int i,int j,int t)
{
    if(i == j)
    {
        if(t == 0)
            return arr[i];
        else
            return -1*arr[i];
    }
    if(t == 0)
    {
        if(dp[i][j] != 0)
            return dp[i][j];
        else
        {
            ll one = arr[i] + recur(i+1, j, (t+1)%2);
            ll two = arr[j] + recur(i, j-1, (t+1)%2);
            
            dp[i][j] = max(one,two);
            return dp[i][j];
        }
    }
    if(t == 1)
    {
        if(dp[i][j] != 0)
            return dp[i][j];
        else
        {
            ll one = recur(i + 1, j, (t + 1)%2) - arr[i];
            ll two = recur(i, j - 1, (t + 1)%2) - arr[j];
            
            dp[i][j] = min(one,two);
            return dp[i][j];
        }
    }
    
    return -1;
}

signed main()
{
    fastio;
//    cout.flush();
    
    int n;
    cin >> n;
    
    F(i,n)
    cin >> arr[i];
    
    ll ans = recur(0, n-1, 0);
    
    cout << ans << endl;
    
    return 0;
}
