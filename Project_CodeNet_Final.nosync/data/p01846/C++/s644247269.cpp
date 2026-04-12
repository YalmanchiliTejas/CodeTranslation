#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

int main () {
  cin.tie(0);
  cout << fixed << setprecision(10);

  while(1) {
    string s; cin >> s;
    if(s == "#") break;
    int sz = s.size();
    int a, b, c, d; cin >> a >> b >> c >> d;
    a--; b--; c--; d--;
    int h = 0, w = 0;
    bool init = true;
    for(int i=0;i<sz;++i) {
      if(init && s[i] == 'b') {
        w++;
      } else if(s[i] == '/') {
        init = false;
        h++;
      } else if(init && s[i] != 'b') {
        w += (int)(s[i] - '0');
      }
    }
    h++;
    
    vector<vector<char>> v(h, vector<char>(w));

    int posh = 0, posw = 0;
    for(int i=0;i<sz;++i) {
      if(s[i] == 'b') {
        v[posh][posw] = 'b';
        posw++;
      } else if(s[i] == '/') {
        posw = 0;
        posh++;
      } else {
        int cnt = (int)(s[i] - '0');
        while(cnt > 0) {
          v[posh][posw] = '.';
          posw++;
          cnt--;
        }
      }
    }

    v[a][b] = '.';
    v[c][d] = 'b';

    for(int i=0;i<h;++i) {
      int cnt = 0;
      for(int j=0;j<w;++j) {
        if(v[i][j] == 'b') {
          if(cnt != 0) cout << cnt;
          cnt = 0;
          cout << "b";
        } else {
          cnt++;
        }
      }
      if(cnt != 0) cout << cnt;
      cnt = 0;
      if(i != h-1) cout << '/';
    }
    cout << endl;
  }
}

