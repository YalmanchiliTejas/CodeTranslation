#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;
#define pival 3.14159265359
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pqq priority_queue
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
ll power(ll x,ll y,ll p) 
{ 
    ll res=1;  
    x=x%p;
    while (y > 0) 
    { 
        if(y&1) 
            res=(res*x)%p; 
        y=y>>1;
        x=(x*x)%p;   
    } 
    return res; 
}
ll arr[3001];
ll dp[3005][3005][5];
ll rec(ll i, ll j, ll t)
{
	if(dp[i][j][t] != -1)
		return dp[i][j][t];
	if(i == j)
	{
		if(t == 1)
			return -arr[i];
		else
			return arr[i];
	}
	dp[i+1][j][1-t] = rec(i+1,j,1-t);
	dp[i][j-1][1-t] = rec(i,j-1,1-t);
	if(t == 0)
		return dp[i][j][t] = max(arr[i] + dp[i+1][j][1-t], arr[j] + dp[i][j-1][1-t]); 
	else if(t == 1)
		return dp[i][j][t] = min(dp[i+1][j][1-t] - arr[i], dp[i][j-1][1-t] - arr[j]);
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,j,k,n;
    cin >> n;
    for(i=0;i<n;i++)
    	for(j=0;j<n;j++)
    		for(k=0;k<2;k++)
    			dp[i][j][k] = -1;
    for(i=0;i<n;i++)
    	cin >> arr[i];
    cout << rec(0,n-1,0) << endl;
	return 0;
}