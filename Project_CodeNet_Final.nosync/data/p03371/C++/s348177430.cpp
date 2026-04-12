#include <bits/stdc++.h>
using namespace std;

int main() {
 int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int z=max(x,y);
  int ans=1e9;
  for(int i=0;i<=2*z;i++){
    int A=max(0,x-i),B=max(0,y-i),sum;
    sum=2*i*c+A*a+B*b;
    ans=min(ans,sum);
  }
  cout<<ans<<endl;
}