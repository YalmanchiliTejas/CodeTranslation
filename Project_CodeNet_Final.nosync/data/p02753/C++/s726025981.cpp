#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int ca=0,cb=0;
  for(int i=0;i<=2;i++){
  		if(s[i]=='A')
          ca+=1;
    	else
          cb+=1;
  }
  if(ca==0 || cb==0)
    cout<<"No";
  else
    cout<<"Yes";
  return 0;
}