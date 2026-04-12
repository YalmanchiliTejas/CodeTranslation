#include <bits/stdc++.h>
using namespace std;
#define rep(i,c,n) for(int i=c;i<n;i++)

int main(){
  string s,a[3];
  cin>>s;
  
  rep(i,0,3){
    a[i]=s.substr(i,1);
  }
  
  if(a[0]==a[1]&&a[1]==a[2]){cout<<"No"<<endl;}
  else{cout<<"Yes"<<endl;}
  
  return 0;
}
