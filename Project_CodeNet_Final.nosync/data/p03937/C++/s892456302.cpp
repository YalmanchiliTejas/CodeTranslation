#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,ans=0;cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++)cin>>s[i];
  for(int i=0;i<h;i++) for(auto c:s[i]) ans+=(c=='#');
  if(ans==h+w-1)puts("Possible");
  else puts("Impossible");
}