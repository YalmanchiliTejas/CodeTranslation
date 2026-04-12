#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >>s;
  bool ok=false;
  for(int i=1;i<s.size();i++){
    if(s[i-1]=='A' && s[i]=='C')ok=true;
  }
  if(ok)cout<<"Yes"<<endl;
  else cout <<"No"<<endl;
}