#include <bits/stdc++.h>
using namespace std;


int main() {
int A,B,C,X,Y;
cin>>A>>B>>C>>X>>Y;
long ans=1e18;

for(int i=0;i<=2*max(X,Y);i+=2){
  int x=max(X-i/2,0);
  int y=max(Y-i/2,0);
  long tmp=i*C;
  tmp+=x*A+y*B;
  ans=min(tmp,ans);
}
cout<<ans<<endl;
}
