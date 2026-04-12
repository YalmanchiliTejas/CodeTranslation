#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;



int main(){
  string s,ans;
  cin >>s;
  if(s[0]==s[1] && s[1]==s[2]) ans="No";
  else ans="Yes";
 
  cout<<ans<<endl;
}
