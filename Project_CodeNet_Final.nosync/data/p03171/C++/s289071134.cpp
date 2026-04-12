#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pie acos(-1)
#define loop(i,a,n) for(int i=a;i<n;i++)
#define trav(a,x) for(auto &a:x)
#define vi vector<int>
#define vl vector<ll>
#define pii pair<ll,ll>
#define endl "\n"
#define w 3005
ll dp[w][w];
vl a(w);
int n;
ll fun(int l ,int r )
{
    ll &memo=dp[l][r];
    if(memo!=-1)
    return memo;
    if(l>r)
    return 0;
    if((r-l)%2==(n-1)%2)
    return memo=max(a[l]+fun(l+1,r),a[r]+fun(l,r-1));
    else
    return memo=min(-a[l]+fun(l+1,r),-a[r]+fun(l,r-1));
}
void solve()
{
    
    cin>>n;
    
    loop(i,0,n)
    cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<fun(0,n-1);
}
int main() {
	// your code goes here
	io;
	
    solve();
	return 0;
}
