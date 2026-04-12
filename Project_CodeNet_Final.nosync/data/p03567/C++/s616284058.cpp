#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int cnt=0;
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]=='A'&&s[i+1]=='C')cnt++;
  }
  if(cnt>0)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return(0);
}