#include<bits/stdc++.h>
using namespace std;

int main (){
  int n;cin>>n;string a;cin>>a;int k;cin>>k;k--;char x=a[k];
  for (int i=0;i<n;i++){
    if (a[i]==x) cout<<x;
    else cout<<"*";
  }
  return 0;
}