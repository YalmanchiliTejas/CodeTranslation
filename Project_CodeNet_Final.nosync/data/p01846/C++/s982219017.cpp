#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int64 i = 0;i < (n);i++)
#define FOR(i, a, b) for(int64 i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value!=0>::type
fill_v(U &u,const V... v){u=U(v...);}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_v(U &u,const V... v){
  for(auto &e:u) fill_v<T>(e,v...);
}

int main(void) {
  string s;
  while (cin >> s && s != "#") {
    int64 w = 0, h = 0;
    REP(i, s.size()) {
      if (s[i] == '/') {
        h++;
        w = 0;
      } else {
        if (s[i] == 'b') w++;
        else w += s[i]-'0';
      }
    }
    vector<vector<int64>> f(h+1, vector<int64>(w, 0));
    h = 0; w = 0;
    REP(i, s.size()) {
      if (s[i] == '/') {
        h++;
        w = 0;
      } else {
        if (s[i] == 'b') {
          f[h][w++] = 1;
        } else {
          w += s[i]-'0';
        }
      }
    }
    int64 a, b, c, d;
    cin >> a >> b >> c >> d; a--; b--; c--; d--;
    f[a][b] = 0;
    f[c][d] = 1;
    string res = "";
    int64 cnt = 0;
    REP(i, f.size()) {
      REP(j, f[i].size()) {
        if (f[i][j] == 1) {
          if (cnt != 0)
            res += (char)('0'+cnt);
          res += 'b';
          cnt = 0;
        } else {
          cnt++;
        }
      }
      if (cnt > 0) res += (char)('0'+cnt);
      cnt = 0;
      if (i < f.size()-1)
        res += '/';
    }
    cout << res << endl;
  }
}
