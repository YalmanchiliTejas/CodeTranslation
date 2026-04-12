#include<bits/stdc++.h>
using namespace std;
string t,p;
char c;
int i,j,k,l,x;
main(){
  for(cin>>t>>p;i<t.size();++i){
    if(t[i]==c&&t[i]!=p[j]){
      c='0';
      break;
    }
    if(t[i]==p[j])++j,c=t[i];
  }
  x=c-'0'?1:0;
  c='0';
  for(reverse(t.begin(),t.end()),reverse(p.begin(),p.end());k<t.size();++k){
    if(t[k]==c&&t[k]!=p[l]){
      c='0';
      break;
    }
    if(t[k]==p[l])++l,c=t[k];
  }
  x&=c-'0'?1:0;
  cout<<(x&&j==p.size()?"yes\n":"no\n");
}