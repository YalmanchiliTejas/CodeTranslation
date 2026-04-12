// OURL: https://atcoder.jp/contests/abc054/tasks/abc054_c
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define RREP(i,a,n) for(int i=(a),i##_len=(n);i<i##_len;++i)
#define MAT1D(V,T,a) vector<T> V (a)
#define MAT2D(V,T,a,b) vector<vector<T>> V (a, vector<T>(b))
#define MAT3D(V,T,a,b,c) vector<vector<vector<T>>> V (a, vector<vector<T>>(b, vector<T>(c)))

// http://beet-aizu.hatenablog.com/entry/2018/04/08/145516
template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){ return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...)); }

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}
template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){ for(auto &e:t) fill_v(e,v); }

template <typename A>
string to_string(A v) { bool first = true; string res = "{"; for (const auto &x : v) { if (!first) { res += ", "; } first = false; res += to_string(x); } res += "}"; return res; }

string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool>::reference b) { return to_string(bool(b)); }
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A>
string to_string(vector<vector<A>> v) { string res; for(const auto &x : v) {res+="\n ";res += to_string(x);} return res;}

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

#ifdef LOCAL
#define debug(...) cerr << "[L" << to_string(__LINE__) << ":" <<#__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N,M;
  cin >> N >> M;
  auto edge = make_v<int>(N,N);
  auto nodes = make_v<int>(N-1);
  iota(nodes.begin(), nodes.end(), 1);

  REP(i,M) {
    int a,b;
    cin >> a >> b;
    edge[a-1][b-1] = edge[b-1][a-1] = 1;
  }
  int ans = 0;
  do {
    bool f = true;
    int p = 0;
    for (auto n : nodes) {
      if (!edge[n][p]) {
        f = false;
        break;
      }
      p = n;
    }
    if (f) ans++;
  } while(next_permutation(nodes.begin(),nodes.end()));
  cout << ans << endl;
  return 0;
}
