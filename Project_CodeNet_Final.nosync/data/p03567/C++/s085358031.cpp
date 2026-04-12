#include<bits/stdc++.h>
using namespace std;
signed main(){
  string a; 
  cin>>a;
  int b=0,c=1;
  for(int i=0;i<a.size();i++){
    if(a[i]=='A'){ 
      if(a[i+1]=='C'){
        cout<<"Yes";
        c=0;
        break;
      }
    }
  }
  if(c) cout<<"No";
  cout<<"\n";
}