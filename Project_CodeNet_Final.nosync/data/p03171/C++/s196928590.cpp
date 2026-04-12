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
// ================================================================================================================================//
// ================================================================================================================================//
// ================================================================================================================================//


int main(){
   FASTIO;
   ll tt=1;
   //cin>>tt;

   while(tt--){
      ll n;
      cin>>n;
      ll a[n];
      ll sum=0;
      fr(0,n){
       cin>>a[i];
      }


      for(ll i=0;i<n;i++){
        dp[i][i]=a[i];
      }


      for(ll len=2;len<=n;len++){

         for(ll i=0;i<n-len+1;i++){
           ll j=i+len-1;
           dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
         }
      }



      cout<<dp[0][n-1]<<"\n";
   }
}
