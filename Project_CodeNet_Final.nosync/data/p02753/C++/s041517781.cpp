#include<bits/stdc++.h>
using namespace std;

int main() {
  
  
  set<char> st;
  string str;
  cin>>str;
  for(int i=0;i<str.length();i++)
  st.insert(str[i]);
  
  if(st.size()==1)
  cout<<"No";
  else
  cout<<"Yes";
  

}