#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,m,n) for (int i = m; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
inline int popcount(const int x) { return __builtin_popcount(x);}
template<class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b;}
template<class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b;}
template<class T> void drop(const T &x) { std::cout<<x<<endl; exit(0);}
void debug_out() { std::cout << "\n";}
template<class T, class... Args> void debug_out(const T &x, const Args &... args) { std::cout<<x<< " "; debug_out(args...);}
#ifdef _DEBUG
  #define debug(...) debug_out(__VA_ARGS__)
#else
  #define debug(...) 
#endif

struct InitIO{
  InitIO() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
  }
}init_io;

int main() {
  int x;
  cin >> x;
  if (x >= 30) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}