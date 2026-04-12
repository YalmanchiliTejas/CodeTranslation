#include<bits/stdc++.h>
using namespace std;
#define int long
signed main(){
  int n;
  string s;
  cin>>n;
  vector<int> a(26,0);
  for(int i=0;i<n;++i){
    cin>>s;
    vector<int> b(26,0);
    for(auto c:s)++b[c-'a'];
    if(!i)a=b;
    else{
      for(int i=0;i<26;++i)a[i]=min(a[i],b[i]);
    }
  }
  s="";
  for(int i=0;i<26;++i){
    while(a[i]--)s+=(char)(i+'a');
  }
  cout<<s;
}