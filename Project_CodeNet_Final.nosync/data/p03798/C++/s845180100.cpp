#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)

int main(){
  int n;string s;cin>>n>>s;
  string x[4]={"SS","SW","WS","WW"};
  bool f=0;
  REP(i,4){
    string a=x[i];
    for(int k=2;k<n+1;k++){
      if((s[k-1]=='o'&&a[k-1]=='S')||(s[k-1]!='o'&&a[k-1]!='S')) a+=a[k-2];
      else a+=(a[k-2]=='S'?'W':'S');
    }
    if(a[0]==a[n]){
      if((a[0]=='S'&&s[0]=='o')||(a[0]=='W'&&s[0]=='x')){
        if(a[n-1]==a[1]) f=1;
      }else if(a[n-1]!=a[1]) f=1;
    }
    if(f){
      a.pop_back();
      cout<<a;
      return 0;
    }
  }
  cout<<("-1");
}