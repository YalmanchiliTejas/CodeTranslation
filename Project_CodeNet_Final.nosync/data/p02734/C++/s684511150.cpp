#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define pll  pair <long long,long long>
#define ss second
#define ff first
#define inf 9223372036854775807
#define maa 998244353
#define ld long double
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define bug(x) cout << #x <<": " << x << '\n';
const ll N=3001 ;
ll dp[N][N] ;
ll n,s ;
vector<ll>a(N) ;
ll fun(ll i,ll j)
{
    if(j==0)
    {
        return n-i+1 ;
    }
    if(i==n)
    {
        if(j==0)
            return 1 ;

        return 0 ;
    }
    else if(dp[i][j]!=-1)
        return dp[i][j] ;
    else
    {
        ll ans=fun(i+1,j) ;
        if(a[i]<=j)
        {

            ans=(ans+fun(i+1,j-a[i]))%maa ;
        }
      //  cout<<i<<" "<<j<<" "<<ans<<endl  ;
        return dp[i][j]=ans ;
    }
}
int main()
{
   fast ;
   ll tests=1 ;
   //cin>>tests ;
   for(ll testcase=1;testcase<=tests;testcase++)
   {
     ///cout<<"Case #"<<testcase<<": " ;
     ///Read ,Think and Test Properly,then code
     cin>>n>>s ;
     for(ll i=0;i<n;i++)
        cin>>a[i] ;

     for(ll i=0;i<N;i++)
     {
         for(ll j=0;j<N;j++)
            dp[i][j]=-1 ;
     }
     ll ans=0 ;

     for(ll i=0;i<n;i++)
     {
         ll x=0 ;
         if(s>=a[i])
            x=fun(i+1,s-a[i]) ;


         //cout<<i<<" "<<x<<endl ;
         x=(x*(i+1))%maa ;

         ans=(ans+x)%maa ;

     }
     cout<<ans ;



   }
}
