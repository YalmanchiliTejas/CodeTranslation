#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f(i,a,b) for(ll i=(a);i<(b);i++)
#define frr(i,a,b) for(ll i=(a-1);i>=(b);i--)
#define vi vector<int>
#define de deque<int>
#define del deque<ll>
#define vl vector<ll>
#define pb push_back
#define ppb pop_back()
#define pf push_front
#define ppf pop_front()
#define mpp map<ll,ll>
#define rev(a) reverse(a.begin(),a.end())
#define srt(a) sort(a.begin(),a.end())
#define ln(a) a.length()
#define sz(a) a.size()
#define endl "\n"
int M=1000000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

int n;cin>>n;
ll a[n];
f(i,0,n)cin>>a[i];
ll dp[n+1][n+1];
memset(dp,0,sizeof dp);
frr(i,n,0)
{
    f(j,i,n)
    {
        if(i==j){if(n%2==1)dp[i][j]=a[i];else{dp[i][j]=-a[i];}}
        else if((i+j+1)%2==n%2)
        {
            dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]);
        }
        else
        {
          dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);
        }
    }

}
cout<<dp[0][n-1]<<endl;

}

