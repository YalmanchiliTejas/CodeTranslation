#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vs = vector<string>;
using vb = vector<bool>;
using vll = vector<long long>;
using vpii = vector<pair<int,int>>;
using vivi = vector<vector<int>>;
using vbvb = vector<vector<bool>>;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int mod = 1000000007;
const int inf = 1001001001;



int main(void) {
  int n;
  cin >> n;
  vs s(n);
  rep(i,n) cin >> s[i];
  vi a(26,inf);
  rep(i,n){
    //cout << i << endl;
    rep(j,26){
      char t = 'a'+j;
      int aa = count(s[i].cbegin(),s[i].cend(),t);
      //cout << aa << endl;
      a[j] = min(aa,a[j]);
    }
  }
  string ans = "";
  rep(i,26){
    rep(j,a[i]){
      char an = 'a'+i;
      ans.push_back(an);
    }
  }
  //rep(i,26) cout << a[i] << endl;
  cout << ans << endl;
  
}


