#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  char s[15];
  cin>>n;
  for(int i=1;i<=n;i++) cin>>s[i];
  cin>>k;
  for(int i=1;i<=n;i++) if(s[k]!=s[i]) s[i]='*';
  for(int i=1;i<=n;i++) cout<<s[i];
  cout<<'\n';
  return 0;
}