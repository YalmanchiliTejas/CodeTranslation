#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const double PI = 3.1415926535897932;
const int MOD = 1e9 + 7;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int n;
  cin >> n;
  map<char, int> alp;
  //for (char ch = 'a'; ch <= 'z'; ch++) alp[ch] = -1;
  rep (i, n) {
    string s;
    cin >> s;
    if (i == 0) {
      for (auto v : s) alp[v]++;
    } else {
      map<char, int> counter;
      for (auto v : s) counter[v]++;
      for (auto v : alp) {
	if (counter[v.first] == v.second || v.second == -1) continue;
	if (counter[v.first] == 0) {
	  alp[v.first] = -1;
	} else {
	  alp[v.first] = min(alp[v.first], counter[v.first]);
	}
      }
    }
  }

  for (auto v : alp) {
    if (v.second == -1) continue;
    for (int i = 0; i < v.second; i++) cout << v.first;
  }
  cout << endl;
  return 0;
}
