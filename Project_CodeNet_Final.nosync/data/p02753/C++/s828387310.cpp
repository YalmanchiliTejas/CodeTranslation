#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define rrep(i, a, b) for (int i = a; i >= (b); i--)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <class T>
inline bool chmin(T& a, T b) {
   if (a > b) {
      a = b;
      return true;
   }
   return false;
}
template <class T>
inline bool chmax(T& a, T b) {
   if (a < b) {
      a = b;
      return true;
   }
   return false;
}
const int INF = 2e9;
const int MOD = 1e9 + 7;

int main() {
   string s;
   cin >> s;
   if (s == "BBB" || s == "AAA")
      cout << "No" << endl;
   else
      cout << "Yes" << endl;
   return 0;
}