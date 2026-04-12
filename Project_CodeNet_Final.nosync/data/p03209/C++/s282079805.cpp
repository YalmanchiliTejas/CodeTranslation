/* 
      Life before Death
      Strength before Weakness
      Journey before Destination
*/
                           
#include <bits/stdc++.h>
using namespace std;
                 
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define per(i,n,a) for (ll i=n;i>a;i--)
#define te ll t; std::cin >> t; while(t--)
#define SZ 500010
//# define M_PIl  3.141592653589793238462643383279502884L 
/*------Just DO IT--------------------------------------*/

ll p[60], b[60] , a[60];

ll f( ll n,ll x){
  if(n==0) return 1;
  if(x<=n) return 0;
  else if(x<=a[n]/2) return f(n-1,x-1);
  else if(x<=a[n]/2 + 2) return p[n-1] + 1;
  else if(x < a[n] - n) return p[n-1]  + 1 + f(n-1 ,x-a[n]/2 -1);
  else return p[n];
}

ll solve(){
  ll n,k;
  cin>>n>>k;
  p[0] =1; a[0] = 1;
  rep(i,1,n+1) {
    p[i] = 2*p[i-1] + 1;
    b[i] = 2*b[i-1] + 2;
    a[i] = 2*a[i-1] + 3;
  }
  cout<<f(n,k)<<endl;
}

int main() {
  fastio;
   solve();
}