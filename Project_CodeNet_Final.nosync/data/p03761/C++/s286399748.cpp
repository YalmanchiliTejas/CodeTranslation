#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cout << H << " "; debug_out(T...); }
#ifdef _DEBUG
  #define debug(...) debug_out(__VA_ARGS__)
#else
  #define debug(...) 
#endif

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n;
  cin >> n;
  int num = 'z'-'a'+1;
  vector<int> cnt(num, 1001001001);
  rep(_,n) {
    string s;
    cin >> s;
    vector<int> res(num, 0);
    rep(i,(int)s.length()) {
      res[s[i]-'a']++;
    }
    rep(i, num) {
      chmin(cnt[i], res[i]); //minを格納
    }
  }
  string ans = "";
  rep(i,num) {
    char x = 'a'+i;
    debug(cnt[i]);
    if (cnt[i] > 0) {
      ans += string(cnt[i], x);
    }
  }
  cout << ans << endl;
  return 0;
}