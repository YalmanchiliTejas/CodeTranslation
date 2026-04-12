#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  #define int long long
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  int ans=A*X+B*Y;
  if(A+B>2*C){
    int r=min(X,Y);
    ans-=A*r+B*r;
    ans+=2*C*r;
  }
  ans=min(ans,max(X,Y)*2*C);
  cout<<ans<<endl;
}