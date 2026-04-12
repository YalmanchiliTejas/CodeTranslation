#include<bits/stdc++.h>
using namespace std;

int main(){
  string str;
  cin>>str;
  set<char> abc(str.begin(), str.end());
  if(abc.size()==1)
    cout<<"No\n";
  else
    cout<<"Yes\n";
  return 0;
}
