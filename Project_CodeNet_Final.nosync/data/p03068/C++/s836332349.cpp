#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int n,k;
  cin>>n>>s>>k;
  char c=s[k-1];
  for(int i=0;i<n;i++)if(s[i]!=c)s[i]='*';
  cout<<s<<endl;
}