#include<bits/stdc++.h>
using namespace std;
int main(){
  int f=0;
  string a;
  cin>>a;
  for(int i=0;i<a.size()-1;i++){
    if(a[i]=='A'&&a[i+1]=='C')f=1;
  }
  if(f)cout<<"Yes";
  else cout<<"No";
  return 0;
}