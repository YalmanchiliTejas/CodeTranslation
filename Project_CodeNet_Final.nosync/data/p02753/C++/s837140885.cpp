#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  string ans="No";
  for(int i=0;i<=1;i++){
    if(s[i]!=s[i+1]){
      ans="Yes";
      break;
    }
  }
  cout<<ans<<endl;
}
