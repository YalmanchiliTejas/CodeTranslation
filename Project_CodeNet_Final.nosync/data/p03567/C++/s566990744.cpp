#include <bits/stdc++.h>
using namespace std;

int main(){
string s;
  cin>>s;
  string ans="No";
  for(int i=0;i<s.size()-1;i++){
    if(s.at(i)=='A'&&s.at(i+1)=='C'){
    ans="Yes";
    }
  }
  cout<<ans<<endl;
}
    