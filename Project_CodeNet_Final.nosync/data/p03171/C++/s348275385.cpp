#include<bits/stdc++.h>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iostream>
#define ios   ios_base::sync_with_stdio(false);  cin.tie(0);    cout.tie(0);
typedef  long long int ll;
using namespace std;
const int M=1e9+7;
const int N=3e3+5;
#define fi first
#define se second
#define pb push_back
#define endl "\n"
ll dp[N][N];
int main()
{
    ios ;
    ll t=1;
  //  cin>>t;
    while(t--)
    {
       ll n;cin>>n;
       ll a[n];
       for(ll i=0;i<n;++i)
       cin>>a[i];
       for(ll i=n-1;i>=0;--i)
       {
           for(ll j=i;j<n;++j)
           {
               if(i==j)
               dp[i][j]=a[i];
               else
               {
                   dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
               }
           }
       }
       cout<<dp[0][n-1];
    }
}