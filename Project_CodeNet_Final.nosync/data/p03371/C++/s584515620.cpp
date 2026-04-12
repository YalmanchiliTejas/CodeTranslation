#include<bits/stdc++.h>
using namespace std;
int main(){
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  int ans1=A*X+B*Y;
  int ans2;
  int tmp=max(X,Y);
  if(tmp==X){
    ans2=X*C*2;
  }else{
    ans2=Y*C*2;
  }
  int tm=min(X,Y);
  int ans3;
  if(tm==X){
    ans3=X*C*2+abs(X-Y)*B;
  }else{
    ans3=Y*C*2+abs(X-Y)*A;
  }
  ans2=min(ans2,ans3);
  ans1=min(ans1,ans2);
  cout<<ans1<<endl;
}