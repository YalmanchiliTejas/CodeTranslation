#include<bits/stdc++.h>
using namespace std;
signed main(){
  int a,c=0,p=0;
  int b[10000];
  cin>>a;
  for(int i=0;i<a;i++){
    cin>>b[i];
  }
  for(int i=0;i<a;i++){
    if(p<=b[i]) c++,p=max(p,b[i]);
  }
  cout<<c<<"\n";
}