#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  bool ans=false;
  for(int i=0;i+1<s.size();i++){
    if(s[i]=='A'&&s[i+1]=='C'){
      ans=true;
    }
  }
  cout<<( ans ?"Yes":"No")<<endl;
  return 0;
}
