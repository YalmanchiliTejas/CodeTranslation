#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,a="No";cin>>s;
  for(int i=0;i<s.size()-1;i++){
    if (s.substr(i,2)=="AC"){
      a="Yes";
      break;
    }
  }
  cout<<a<<endl;
}