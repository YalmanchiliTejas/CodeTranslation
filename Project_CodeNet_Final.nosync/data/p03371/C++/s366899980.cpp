#include<bits/stdc++.h>
using namespace std;
int i,j,n,l=1000000000,a,b,c,m;
int main(){
  for(cin>>a>>b>>c>>n>>m;i<=max(n,m);i++)l=min(l,2*c*i+a*max(0,n-i)+b*max(0,m-i));
  cout<<l;
}