#include<bits/stdc++.h>
using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
main(){
  string s,t;
  cin>>s>>t;
  vector<int>v1,v2;
  int c1=0,c2=0;
  r(i,s.size()){
    if(s[i]==t[c1]){
      v1.push_back(i);
      c1++;
    }
  }
  reverse(t.begin(),t.end());
  r(i,s.size()){
    if(s[s.size()-i-1]==t[c2]){
      v2.push_back(s.size()-1-i);
      c2++;
    }
  }
  reverse(v1.begin(),v1.end());
  if(v1.size()!=t.size())cout<<"no"<<endl;
  else if(v1!=v2)cout<<"no"<<endl;
  else cout<<"yes"<<endl;
}