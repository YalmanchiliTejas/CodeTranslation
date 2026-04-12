#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main(){
  string s;
  cin >> s;
  string ans="No";
  rep(i,s.size()-1){
    if(s.at(i)!=s.at(i+1)) ans="Yes";
  }
  cout<<ans<<endl;
}
