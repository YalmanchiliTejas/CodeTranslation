#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;

int n;
string s;
vector<bool> a;

bool judge() {
  vector<bool> t;
  t.push_back(a[n - 1]);
  rep(i, n) t.push_back(a[i]);
  t.push_back(a[0]);
  
  rep(i, n) {
    auto ok = [&](bool left, bool right) {
      int c = s[i];
      bool animal = a[i];
      if(animal == false) {
        if (c == 'o') {
          if (left == right) return true;
        } else {
          if (left != right) return true;
        }
      } else {
        if(c == 'x') {
          if (left == right) return true;
        } else {
          if (left != right) return true;
        }
      }
      return false;
    };

    if(!ok(t[i], t[i + 2])) return false;
  }
  return true;
}


int main() {

  cin >> n >> s;

  auto ok = [&] {
    rep(start1, 2) {
      rep(start2, 2) {
        a = vector<bool>(n, 0); // falseのとき羊、trueの時オオカミ
        a[0] = bool(start1);
        a[1] = bool(start2);
        for (int i = 1; i < n; ++i) {
          if (i == n - 1) {
            if(judge()) return true;

          } else {
            if (a[i] == false) {
              if (s[i] == 'o') a[i + 1] = a[i - 1];
              else a[i + 1] = !a[i - 1];
            } else {
              if (s[i] == 'x') a[i + 1] = a[i - 1];
              else a[i + 1] = !a[i - 1];
            }
          }
        }
      }
   }
   return false;
  }();

  if(!ok) {
    cout << -1 << endl;
    return 0;
  }

  string ans;
  rep(i, n) {
    if(a[i] == false) ans += "S";
    else ans += "W";
  }
  cout << ans << endl;
}