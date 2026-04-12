#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin>>s;
  int a=0,b=0;
  for(int i=0;i<3;i++){
    if(s[i]=='A'){
      a++;
    }
    else{
      b++;
    }
  }
  if(a!=0 && b!=0){
    cout<<"Yes\n";
  }
  else{
    cout<<"No\n";
  }
  return 0;
}