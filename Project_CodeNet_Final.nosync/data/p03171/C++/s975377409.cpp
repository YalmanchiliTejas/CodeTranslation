#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO ios_base::sync_with_stdio(false);cout.tie(NULL);cout.tie(NULL);
#define fr(a,b) for(long long i=a;i<b;i++)
#define vi vector<ll>
const ll MAX=1e4;
const ll mod=1e9+7;
const ll INF=1e18+12;
set< pair<ll,ll> >ss;
ll dp[MAX][MAX];

                                    //SAMEER KUMAR SINGH//
// ==========================================================================================================//

ll fun(ll a[],ll i,ll j){
   if(i>j)
   return 0;
   if(dp[i][j]!=0)
    return(dp[i][j]);
   ll f1=a[i]+min(fun(a,i+2,j),fun(a,i+1,j-1));
   ll f2=a[j]+min(fun(a,i+1,j-1),fun(a,i,j-2));
   dp[i][j]=max(f1,f2);
   return(dp[i][j]);
}
int main(){
   FASTIO;
   ll tt=1;
   //cin>>tt;

   while(tt--){
     ll n;cin>>n;

     ll a[n];
     ll sum=0;
     fr(0,n){
     cin>>a[i];
     sum+=a[i];
     }

     //cout<<dp[3][3]<<" "<<dp[4][5]<<"\n";
     cout<<2*fun(a,0,n-1)-sum;
   }
}
