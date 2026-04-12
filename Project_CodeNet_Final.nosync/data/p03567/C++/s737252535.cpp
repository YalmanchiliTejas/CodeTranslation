#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  bool fl=false;
  for(int i=0; i<s.size()-1; i++){
    if(s.substr(i,2)=="AC"){
      fl=true;
      break;
    }
  }
  if(fl)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}