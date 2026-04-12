#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int ans=0;
  int now=0;
  for(int i=0;i<n;i++){
     int a;
     cin>>a;
    ans+=!!(now<=a);
    now=max(now,a);
  }
  cout<< ans<<endl;
  return 0;
}