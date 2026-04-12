#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
char al[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int main(){
  int n;
  cin >> n;
  vector<vector<int>> cnt(n,vector<int>(26,0));
  rep(i,n) {
    string s;
    cin >> s;
    rep(j,sz(s)) cnt[i][s[j] - 'a']++;
  }
  vector<int> res(26,100);
  rep(i,26) {
    rep(j,n) {
      res[i] = min(res[i],cnt[j][i]);
    }
  }
  string ans = "";
  rep(i,26) rep(j,res[i]) ans += al[i];
  cout << ans << endl;
  return 0;
}