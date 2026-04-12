#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
#define rep(i,m,n) for(int i=m;i<n;i++)
#define co(n) cout<<n<<endl
#define all(n) (n).begin(),(n).end()
#define pb(n,m) n.push_back(m)
#define pi(n,m) n.insert(n.begin(),m);
#define ee(n) n.erase(n.end()-1)
#define eb(n) n.erase(n.begin())
using namespace std;
//using bint=boost::multiprecision::cpp_int;
typedef long long ll;
typedef unsigned long long ull;

int main(){
  ll a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  ll ans=10000000000000;
  ans=min(ans,a*x+b*y);
  ll z=min(x,y),s=abs(x-y),d;
  if(x>=y) d=a;
  else d=b;
  ans=min(ans,c*2*z+s*d);
  ans=min(ans,c*2*max(x,y));
  co(ans);
  
  return 0;
}