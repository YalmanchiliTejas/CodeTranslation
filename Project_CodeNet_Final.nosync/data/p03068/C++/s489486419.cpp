#include<bits/stdc++.h>
using namespace std;
#define INF -2147483647
#define mod 1000000007
signed main(){
  int a,c;
  string b;
  cin>>a>>b>>c;
  for(int i=0;i<a;i++){
    if(b[c-1]!=b[i]) cout<<"*";
    else cout<<b[i];
  }
  cout<<"\n";
}
