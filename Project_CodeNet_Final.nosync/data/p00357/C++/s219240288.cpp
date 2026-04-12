#include<bits/stdc++.h>
using namespace std;
int n;
int t[300000];

int solve(){
  int l=0;
  for(int i=0;i<n;i++){
    if(l<i*10)return 0;
    l=max(l,i*10+t[i]);
  }
  return 1;
}

int main(){
  cin>>n;
  for(int i=0;i<n;i++)cin>>t[i];
  int a=solve();
  reverse(t,t+n);
  int b=solve();
  if(a==1&&b==1)cout<<"yes"<<endl;
  else cout<<"no"<<endl;
  return 0;
}
