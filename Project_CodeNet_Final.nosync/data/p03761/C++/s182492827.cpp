#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  int n; cin >> n;
  vector<vi> v(n,vi(26));
  rep(i,n){
    string s; cin >> s;
    rep(j,s.size()) v[i][s[j]-'a']++;
  }
  string ans = "", txt = "abcdefghijklmnopqrstuvwxyz";
  rep(i,26){
    int mn = INF;
    rep(j,n) chmin(mn,v[j][i]);
    rep(j,mn) ans += txt[i];
  }
  cout << ans;
  cout << "\n";
  return 0;
}
