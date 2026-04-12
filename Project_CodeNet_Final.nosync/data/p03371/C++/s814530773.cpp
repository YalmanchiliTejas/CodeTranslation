#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, X, Y;
  cin>>A>>B>>C>>X>>Y;

  // AとBのみ or  ABをmaxまでかで比較すればOK
  int ans = X*A + Y*B;
  if(X>Y){
    ans = min(ans, Y*2*C + (X-Y) * A);
    ans = min(ans,X*2*C);
  }
  else{
    ans = min(ans, X*2*C + (Y-X)*B);
    ans = min(ans,Y*2*C);
  }
  cout<<ans<<endl;

}
