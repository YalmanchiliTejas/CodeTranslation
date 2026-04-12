#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  
  ll tmp1=A*X+B*Y;
  ll tmp3=max(X,Y)*C*2;
  ll tmp2;
  if(X>=Y)tmp2=Y*2*C+(X-Y)*A;
  else tmp2=X*2*C+(Y-X)*B;
  ll ans=min(tmp1,tmp2);
  ans=min(ans,tmp3);
  cout<<ans<<endl;
}