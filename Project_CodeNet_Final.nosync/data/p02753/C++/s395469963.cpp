#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  
  string ans="Yes";
  if(S.at(0)==S.at(1) && S.at(0)==S.at(2)){
    ans="No";
  }
  
  cout<<ans<<endl;
}