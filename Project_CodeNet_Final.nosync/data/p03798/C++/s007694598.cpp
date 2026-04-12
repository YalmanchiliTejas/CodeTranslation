#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)

int main(){
  int n;string s;cin>>n>>s;
  string x[4]={"SS","SW","WS","WW"};
  bool f=0;
  REP(i,4){
    string ans=x[i];
    for(int k=2;k<n+1;k++){
      if((s.at(k-1)=='o'&&ans.at(k-1)=='S')||(s.at(k-1)!='o'&&ans.at(k-1)!='S')){
        ans.push_back(ans.at(k-2));
      }else{
        if(ans.at(k-2)=='S') ans.push_back('W');
        else ans.push_back('S');
      }
    }
    if(ans.at(0)==ans.at(n)){
      if(ans.at(0)=='S'&&s.at(0)=='o'&&ans.at(n-1)==ans.at(1)) f=1;
      if(ans.at(0)=='S'&&s.at(0)=='x'&&ans.at(n-1)!=ans.at(1)) f=1;
      if(ans.at(0)=='W'&&s.at(0)=='o'&&ans.at(n-1)!=ans.at(1)) f=1;
      if(ans.at(0)=='W'&&s.at(0)=='x'&&ans.at(n-1)==ans.at(1)) f=1;
    }
    if(f){
      ans.pop_back();
      cout<<ans;
      return 0;
    }
  }
  cout<<("-1");
}