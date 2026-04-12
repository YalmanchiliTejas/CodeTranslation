#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)

int main(){
  int n;string s;cin>>n>>s;
  bool f=0;
  REP(i,2) REP(j,2){
    string ans="";
    REP(k,n+1){
      if(k==0){
        if(i==0) ans.push_back('S');
        else ans.push_back('W');
      }else if(k==1){
        if(j==0) ans.push_back('S');
        else ans.push_back('W');
      }else{
        if(s.at(k-1)=='o'){
          if(ans.at(k-1)=='S') ans.push_back(ans.at(k-2));
          else{
            if(ans.at(k-2)=='S') ans.push_back('W');
            else ans.push_back('S');
          }
        }else{
          if(ans.at(k-1)=='S'){
            if(ans.at(k-2)=='S') ans.push_back('W');
            else ans.push_back('S');
          }else ans.push_back(ans.at(k-2));
        }
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