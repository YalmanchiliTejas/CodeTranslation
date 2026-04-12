#include<bits/stdc++.h>
using namespace std;
main(){
  string s;
  cin>>s;
  for(int i=0;i<s.size()-1;++i)if(s.substr(i,2)=="AC")return cout<<"Yes",0;
  cout<<"No";
}