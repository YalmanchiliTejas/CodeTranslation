#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k;;
  cin>>n;
  char s[n];
  cin>>s>>k;
  char tem=s[k-1];
  for(int i=0;i<n;++i){
    if(s[i]!=tem){
      s[i]='*';
    }
  }
  cout<<s;
  return 0;
}
