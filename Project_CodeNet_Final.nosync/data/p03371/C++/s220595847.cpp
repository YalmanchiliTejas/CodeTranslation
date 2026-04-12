#include <bits/stdc++.h> 
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(vec) vec.begin(), vec.end()
#define tmax(x,y,z) max((x),max((y),(z)))
#define tmin(x,y,z) min((x),min((y),(z)))
typedef long long ll;ll MM = 1000000000;ll mod = MM + 7; ll MMM=9223372036854775807;//2^63 -1
ll GCD(ll x, ll y) {if (y == 0) return x;else return GCD(y, x % y);}
ll LCM(ll x, ll y) { return x / GCD(x, y) * y;}
//cout << fixed << setprecision(10);

int main(){
 ll a,b,c,x,y,ans=0; cin>>a>>b>>c>>x>>y;
 ll t=min(x,y);
  ans+=t*min(c*2,a+b);
  if(x-t>0)ans+=(x-t)*min(a,2*c);
  if(y-t>0)ans+=(y-t)*min(b,c*2);
  
  cout<<ans<<endl;
}