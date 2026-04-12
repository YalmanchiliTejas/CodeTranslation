#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define all(x) (x).begin(), (x).end()
#define int long long
#define double long double

main(){
	int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int d,e,f;
  d=x*a+y*b;
  f=max(x,y)*c*2;
  if(x>=y) e=y*c*2+(x-y)*a;
  else e=x*c*2+(y-x)*b;
  cout<<min(d,min(f,e))<<endl;
}
