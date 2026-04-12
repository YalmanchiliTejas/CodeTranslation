#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define vl vector<long long int>
#define vvl vector<vector<ll> > 
#define fo(i,a,b) for(int i=a;i<b;i++)
#define rof(i,a,b)  for(int i=b;i>=a;i--)
using namespace std;
ll mod=1000000007;
ll dp[3100][3100][2],a[3100];
ll cnt(ll i,ll j,ll taro)
{
    if(i>j)
        return 0;
    if(dp[i][j][taro]!=-1)
        return dp[i][j][taro];
    if(taro)
    {
        dp[i][j][taro] = max(a[i]+cnt(i+1,j,0),a[j]+cnt(i,j-1,0));
    }
    else
        dp[i][j][taro] = min(cnt(i+1,j,1),cnt(i,j-1,1));
    return dp[i][j][taro];
}
int main()
{
    ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    ll n;cin>>n;
    ll tot=0;
    memset(dp,-1,sizeof(dp));
    fo(i,0,n)
        cin>>a[i],tot+=a[i];
    ll maxi = cnt(0,n-1,1);
    cout << maxi-(tot-maxi);
}

