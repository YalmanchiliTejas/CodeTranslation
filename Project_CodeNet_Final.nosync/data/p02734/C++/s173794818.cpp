// ABEY SAALE
// QUESTION KHUD KR SOLUTION KYU DEKH RHA H
 
 
 
 
 
 
 
 
//MAAF KIJIYEGA ME GUSSE ME IDHAR UDHAR NIKAL JATA HU
#include<bits/stdc++.h>
#define mod 998244353
#define fr first
#define se second
#define ll long long
#define PI 3.1415926535 
#define pb push_back
#define mpr make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define senky_bansal ios_base::sync_with_stdio(false);
#define IIIT_ALLAHABAD    cin.tie(NULL);cout.tie(NULL);
using namespace std;

ll fac[2000005];
void pre(){ fac[0]=1; fac[1]=1; for(int i=2;i<200005;i++) fac[i]=(i*fac[i-1])%mod;}
ll power(ll a,ll b){ll res=1;while(b){if(b&1) res=(res*a)%mod;a=(a*a)%mod;b=b/2;}return res%mod;}
ll ncr(ll n,ll r){return ((fac[n]*power(fac[r],mod-2))%mod*power(fac[n-r],mod-2))%mod;}
// DEKHIYE JI  WALID JO THE ABBA HAMARE WO YEH function CHHOD KR GYE THE
ll n,s;
ll a[3005];
ll dp[3005][3005];
signed main()
{   


      
      senky_bansal
      IIIT_ALLAHABAD
      
      // pre();
      ll t;
      // cin>>t;
      t=1;
      while(t--)
      { 
        ll ans =0;
        cin>>n>>s;
         for(int i=0;i<n;i++)
         {
             cin>>a[i];
             memcpy(dp[i+1],dp[i],sizeof(dp[i+1]));
             dp[i+1][a[i]]=(dp[i+1][a[i]]+i+1)%mod;
             for(int j=0;j+a[i]<=s;j++)
             {
                 dp[i+1][j+a[i]]+=dp[i][j];
                 dp[i+1][j+a[i]]%=mod;
             }
             ans+=dp[i+1][s];
             ans%=mod;
         }
         cout<<ans<<endl;
         

      }
      






}

























