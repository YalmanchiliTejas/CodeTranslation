#include<bits/stdc++.h>
using namespace std;
#define rep(i ,a, n) for (long long int i=a;i<=n;i++)
#define pb  push_back
#define mp make_pair
#define fp first
#define sp second
#define be(v) v.begin(),v.end()
typedef long long ll;
typedef vector<ll> vi ;
typedef vector<pair<ll , ll > >  vpi ;
const int ma1=1e5+5;
string no="NO",yes="YES";
#define MOD 1000000007
int max_char=26;

ll sol(vector<ll> &a,vector< vector<ll> > &dp, int s,int e)
{

    if(s+1==e)
        return max(a[s],a[e]);
        if(s==e)
            return a[s];
    if(dp[s][e]!=-1)
        return dp[s][e];
    return dp[s][e]=max(a[s]+min(sol(a,dp,s+2,e),sol(a,dp,s+1,e-1)),a[e]+min(sol(a,dp,s+1,e-1),sol(a,dp,s,e-2)));
}

int main()
{
      ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;

    while(t--)
    {

         ll n;
         cin>>n;
         ll sum=0;
        vector<ll> a(n);
        vector<vector<ll>> dp(n,vector<ll> (n,-1));
         for(int i=0;i<n;i++)
           {

            cin>>a[i];
            sum=sum+a[i];
        }
        ll x=sol(a,dp,0,n-1);
        ll y=sum-x;
        cout<<x-y;
    }
    return 0;
}














