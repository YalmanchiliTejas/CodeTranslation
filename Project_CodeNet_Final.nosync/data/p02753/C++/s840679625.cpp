#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=int(a);i<=int(b);i++)

int main(){
  string s;
  cin>>s;
  
  set <char> con;
  F(i,0,2) con.insert(s[i]);
  if(con.size()>1) cout<<"Yes";
  else cout<<"No";
}