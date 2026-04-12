#include <bits/stdc++.h>
using namespace std;

int main(){
 	
  char str[3];
  cin>>str[0];
  int flag=1;
  for(int i=1;i<3; ++i){
    cin>>str[i];
  	if(str[i] != str[0]){
      flag = 0;
    	break;
    }
  }
  if(flag) cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
  
  return 0;
}