#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  int n,k;
  string s;
  cin>>n;
  cin>>s;
  cin>>k;
  char c[n];
  for(i=0;i<n;i++){
    if(s[i]!=s[k-1])c[i]='*';
    else c[i]=s[i];
  }
  for(i=0;i<n;i++)cout<<c[i];
}