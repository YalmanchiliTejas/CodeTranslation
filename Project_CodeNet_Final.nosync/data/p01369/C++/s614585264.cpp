#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (int i = (int)a; i < (int)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define MOD 1000000007
#define INF 1000000000
#define PI 3.14159265359
#define EPS 1e-12

int main(void) {
  char left[15] = {'q', 'w', 'e', 'r', 't', 'a', 's', 'd',
                   'f', 'g', 'z', 'x', 'c', 'v', 'b'};
  char right[11] = {'y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'n', 'm'};

  while (true) {
    string str;
    cin >> str;
    if(str == "#") break;

    bool isleft;
    REP(i, 15) if (left[i] == str[0]) isleft = true;
    REP(i, 11) if (right[i] == str[0]) isleft = false;
    /*
    if(isleft) cout << "left" << endl;
    else cout << "right" << endl;
  */
    int cnt = 0;
    FOR(i, 1, str.size()) {
      //????????????????§??????????
      if (isleft) {
        REP(j, 11) {
          // cout << right[j] << " ";
          if (right[j] == str[i]) {
            cnt++;
            isleft = false;
          }
        }
      } else {
        REP(j, 15) {
          // cout << left[j] << " ";
          if (left[j] == str[i]) {
            cnt++;
            isleft = true;
          }
        }
      }
      //cout << endl;

      // if(isleft) cout << "left " << str[i] << endl;
      // else cout << "right " << str[i] << endl;
    }

    cout << cnt << endl;
  }

  return 0;
}