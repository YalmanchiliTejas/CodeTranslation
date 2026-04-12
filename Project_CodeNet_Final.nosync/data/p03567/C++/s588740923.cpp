#include <bits/stdc++.h>
using namespace std;
signed main(){
  char s[200];
  int a;
  cin>>s;
  for(int i=0;i<10;i++){
    if(s[i]=='A'){
      a=i;
    }
    if(s[i]=='C')
      if(a+1==i){
	cout<<"Yes"<<endl;
	return(0);
      }
  }
  cout<<"No"<<endl;
  return(0);
}
    
