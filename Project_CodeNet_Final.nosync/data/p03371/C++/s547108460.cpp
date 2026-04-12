#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  ll a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  ll d=min(a+b,2*c);
  if(x>=y){cout<<d*y+(x-y)*min(a,2*c);}
  else{cout<<d*x+(y-x)*min(b,2*c);}
}
      

