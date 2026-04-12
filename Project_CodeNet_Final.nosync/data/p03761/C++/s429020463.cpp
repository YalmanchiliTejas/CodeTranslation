#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=int64_t;

int main(){
  int n; cin >>n;
  vector<int> ans(26,INT_MAX);
  rep(i,0,n) {
    vector<int> temp(26);
    string s; cin >>s;
    rep(j,0,s.size()) temp[s[j]-'a']++;
    rep(k,0,26) ans[k]=min(ans[k],temp[k]);
  }
  rep(i,0,26) {
    rep(j,0,ans[i]) cout <<char(i+'a');
  }
  cout <<endl;
  return 0;
}
