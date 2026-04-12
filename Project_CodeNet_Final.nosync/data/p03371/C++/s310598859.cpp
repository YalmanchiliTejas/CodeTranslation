#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;

int main(){
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  int ans=A*X+B*Y;
  if(X>Y){
    ans=min(ans,2*X*C);
    ans=min(ans,2*Y*C+A*(X-Y));
  }else{
    ans=min(ans,2*Y*C);
    ans=min(ans,2*X*C+B*(Y-X));
  }
  cout<<ans<<endl;
}
