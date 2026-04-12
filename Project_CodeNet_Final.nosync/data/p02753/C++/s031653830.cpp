#include<bits/stdc++.h>
using namespace std;

int main(){
  
 string s; cin>>s;
  set<char> st;
  for(char c : s ) st.insert(c);
  
  if(st.size()>1) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  
  
  return 0;
}