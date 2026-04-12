#include <iostream>
using namespace std;
typedef long long ll;

int main(){
  ll a,b,c; cin>>a>>b>>c;
  ll x,y; cin>>x>>y; ll an=1e18;
  for(int i=0;i<=max(x*2, y*2);i++) {
    ll sm=2*c*i;
    sm += max(0LL, a*(x-i));
    sm += max(0LL, b*(y-i));
    an = min(sm,an);
  }
  cout<<an<<endl;
}