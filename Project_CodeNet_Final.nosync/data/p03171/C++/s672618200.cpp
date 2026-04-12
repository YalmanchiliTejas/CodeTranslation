#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fastt ios_base::sync_with_stdio(false); cin.tie(NULL)
#define debug1(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define debug3(x,y,z) cout<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl

typedef long long ll;
typedef pair<ll,ll> pii;
const ll modd=1e9+7;

ll poww(ll a,ll b){
  ll ans=1;
  while(b>0){
    if(b%2==1) ans=(ans*a);
    a=(a*a);
    b=b/2;
  }
  return ans;
}

/*-----------------------------------------------------------------------*/

ll dp[3001][3001];

int main(){
   fastt;

   ll n;
   cin>>n;

   vector <ll> a(n);

   for(ll i=0;i<n;i++) { 
   	cin>>a[i];
   	if(n%2==1)
       dp[i][i]=a[i];
    else
       dp[i][i]=-a[i];
   }

   for(ll siz=2;siz<=n;siz++)
   	   for(ll start=0;start+siz-1<n;start++){
   	   	   ll check;
   	   	   if(siz%2==n%2)
   	   	   	  check=1;
   	   	   else
   	   	   	  check=0;
   	   	   if(check==1)
   	   	      dp[start][start+siz-1]=max(a[start]+dp[start+1][start+siz-1],a[start+siz-1]+dp[start][start+siz-2]);
   	   	   else
   	   	   	  dp[start][start+siz-1]=min(-a[start]+dp[start+1][start+siz-1],-a[start+siz-1]+dp[start][start+siz-2]);
   	   }

   cout<<dp[0][n-1]<<endl;

   return 0;
}
