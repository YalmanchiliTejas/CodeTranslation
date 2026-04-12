//Tonight's the night and it is going to happen again and again.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define T ll t; cin>>t; while(t--)
#define mod 1000000007
#define f(n) for(ll i = 0;i<n;i++)
#define endl "\n"
ll gcd(ll a,ll b){if(b==0){return a;}return gcd(b,a%b);}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   ll n;cin>>n;ll dp[n+1][n+1];memset(dp,0,sizeof(dp));ll sum=0;
   ll a[n];f(n){cin>>a[i];sum+=a[i];}
   for(ll i=n-1;i>=0;i--)
   {
     for(ll j=i;j<n;j++)
     {
     	if(i==j){dp[i][j]=a[i];}
     	else{
      dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);}//segmwnt can be represented by
      //2 states.
     }
   } 
   cout<<dp[0][n-1]; 
}
