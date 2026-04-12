#include <bits/stdc++.h>

using namespace std;


int main(){
  string s;
  cin>>s;
  int isa=0,isb=0;
  for(int i=0;i<3;i++){
      if(s[i]=='A'){
          isa=1;
      }
      if(s[i]=='B'){
          isb=1;
      }
  }
  
  if(isa==1 && isb==1){
      cout<<"Yes";
  }
  else{
      cout<<"No";
  }
  
  
  
  return 0;
}
 