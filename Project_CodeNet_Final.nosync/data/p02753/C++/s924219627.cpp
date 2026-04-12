#include <bits/stdc++.h>
using namespace std;

signed main(){
  char c;
  bool a=0, b=0;
  for(int i=0;i<3;i++){
    cin>>c;
    if(c == 'A'){
      a=1;
    } else {
      b=1;
    }
  }
  if(a && b){
    cout<<"Yes\n";
  } else {
    cout<<"No\n";
  }
  return(0);
}