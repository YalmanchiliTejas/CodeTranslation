#include <bits/stdc++.h>
#include <map> // pair
using namespace std;
int main(){
  int A,B,C,X,Y;
  int ans;
  cin>>A>>B>>C>>X>>Y;

    if(X>Y){
      ans = min(X,Y)*2*C+(X-Y)*A;
    }else{
      ans = min(X,Y)*2*C+(Y-X)*B;
    }
    ans = min(ans,X*A+Y*B);
    ans = min(ans,2*C*max(X,Y));

  cout<<ans<<endl;
}
