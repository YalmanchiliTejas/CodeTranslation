#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int a=-10;
  int b=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='A')a=i;
    if(s[i]=='C'&&a-i==-1)b=1;
  }
  if(b==1)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}