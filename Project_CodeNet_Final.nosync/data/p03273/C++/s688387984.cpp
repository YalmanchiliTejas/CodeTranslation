#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0;i < n;i++)
#define REP(i,n,k) for(int i = n;i < k;i++)
#define P(p) cout << (p) << endl;
#define sP(p) cout << setprecision(15) << fixed << p << endl;
#define vi vector<int>
#define printv(v) for(int i = 0;i < v.size();i++)P(v[i]);
#define printt(a,b) cout << a << " " << b << endl; 
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int dx[] = { 1, -1 , 0 , 0};
int dy[] = { 0,  0,  1, -1};
int MOD = 1e9 + 7;

void solve() {
  int h,w;
  cin >> h >> w;
  vector<string> v;
  vector<int> p;
  rep(i,h){
    string s;
    cin >> s;
    bool f = true;
    rep(j,s.length()){
      if(s[j] == '#'){
        f = false;
      }
    }
    if(!f){
      v.pb(s);
    }
  }
  rep(i,w){
    string s = "";
    rep(j,v.size()){
      s = s + v[j][i];
    }
    bool f = true;
    rep(j,s.length()){
      if(s[j] == '#'){
        f = false;
      }
    }
    if(!f){
      p.pb(i);
    }
  }
  rep(i,v.size()){
    rep(j,p.size()){
      cout << v[i][p[j]];
    }
    cout << endl;
  }
}

int main() {
  solve();
  return 0;
}
