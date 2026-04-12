#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1L << (x))
using ll = long long;
using namespace std;

template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
 
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}

/**
 * sheep => 0, wolf => 1
 */

int main() {
  int n; cin >> n;
  string s; cin >> s;

  function<int(int, int, int)> retA = [](int a, int self, char c){
    if(self == 0 && c == 'o' || self == 1 && c == 'x')
      return a;
    else
      return 1-a;
  };

  REP(i, 2)REP(j, 2){
    vector<int> c(n);
    c[0] = i; c[1] = j;

    FOR(i, 1, n-1) c[i+1] = retA(c[i-1], c[i], s[i]);

    if(retA(c[n-2], c[n-1], s[n-1]) == c[0] && retA(c[1], c[0], s[0]) == c[n-1]){
      for(const auto& a: c){
        cout << (a? 'W': 'S');
      }
      cout << endl;
      
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}
