#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll a,b,c,x,y;scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&x,&y);c *= 2;
  printf("%lld\n",min({a*x+b*y,min(x,y)*c+(x-min(x,y))*a+(y-min(x,y))*b,max(x,y)*c}));
}