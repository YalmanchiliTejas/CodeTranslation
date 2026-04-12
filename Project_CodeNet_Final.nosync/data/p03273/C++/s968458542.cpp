#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int H, W; cin >> H >> W;
  vector<string> S;
  REP(i, H){
    string s; cin >> s;
    bool flag = false;
    REP(j, W){
      if(s[j] == '#') flag = true;
    }
    if(flag) S.push_back(s);
  }
  int N = S.size();
  vector<bool> b(W, false);
  REP(i, W){
    REP(j, N){
      if(S[j][i] == '#') b[i] = true;
    }
  }
  vector<string> ans;
  REP(i, N){
    string a;
    REP(j, W){
      if(b[j]) a += S[i][j];
    }
    ans.push_back(a);
  }
  for(auto i : ans){
    cout << i << endl;
  }
}