#include<iostream>
#include<vector>
#include<utility>
#include<math.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pair<int, int> > vp;

#define pb push_back
#define inf 999999999
#define rep(i, n) for(int i = 0; i < n; i++)
#define For(i, a, n) for(int i = a; i < n; i++)
#define out(n) cout << n << endl;
#define vout(v) rep(i, v.size()) out(v[i]);

int main() {
  int a;
  cin >> a;
  vector<string> s(a);
  vvi vv(a);
  string str = "abcdefghijklmnopqrstuvwxyz";

  rep(i, a) {
    cin >> s[i];
    vector<ll> l(26, 0);
    rep(j, s[i].length()) {
      rep(k, str.length()) {
        if(s[i][j] == str[k]) {
          l[k]++;
          break;
        }
      }
    }
    vv[i] = l;
  }

  rep(i, 26) {
    int flag = inf;
    rep(j, vv.size()) {
      if(!vv[j][i]) {
        flag = 0;
        break;
      }
      if(vv[j][i] < flag) flag = vv[j][i];
    }
    rep(j, flag) {
      cout << str[i];
    }
  }

  cout << endl;

}
