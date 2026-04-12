#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int n;
  cin>>s>>n;
  int a=s[0]-'0',c=s[0]-'0',b=0;
  for(int i=1;i<s.size();i+=2){
    int p=s[i+1]-'0';
    if(s[i]=='+')a+=p,b+=c,c=p;
    else a*=p,c*=p;
  }
  b+=c;
  if(b==n&&a!=n)cout<<'M';
  else if(a==n&&b!=n)cout<<'L';
  else if(a==b&&a==n)cout<<'U';
  else cout<<'I';
  cout<<endl;
  return 0;
}