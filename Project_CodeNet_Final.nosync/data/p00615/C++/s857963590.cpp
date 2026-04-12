#include <bits/stdc++.h>
using namespace std;

int main(){
  while(1){
  int n,m;
  cin>>n>>m;
  if(!n&&!m)break;
  int a[20010]={};
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<m;i++)cin>>a[i+n];
  
  sort(a,a+n+m+1);
  
  int ans=0;
  for(int i=1;i<=n+m;i++) ans=max(ans,a[i]-a[i-1]);
  cout <<ans<<endl;
  

  }

  return 0;
}