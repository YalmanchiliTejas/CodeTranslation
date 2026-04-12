#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


#define INF 1000000000000


signed main()
 {
int a,b,c,x,y;
cin>>a>>b>>c>>x>>y;
if(a+b<2*c){cout<<a*x+b*y;}
else{
  int k=0;
  if(x>=y){k=c*y*2+a*(x-y);}
  else k=c*x*2+b*(y-x);
  cout<<min(k,c*max(x,y)*2);
}
}
