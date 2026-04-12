#include<bits/stdc++.h>
using namespace std;
int i,j,a,n,b,c,l,k,m=0;
int main()
{
  for(cin>>n;i<n;i++){
    cin>>a;
    m=max(a,m);
    if(a==m)c++;
  }
  cout<<c;
}