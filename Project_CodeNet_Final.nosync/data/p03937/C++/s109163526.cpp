#include <bits/stdc++.h>
using namespace std;

#define _p(...) (void)printf(__VA_ARGS__)
#define forr(x,arr) for(auto&& x:arr)
#define _overload3(_1,_2,_3,name,...) name
#define _rep2(i,n) _rep3(i,0,n)
#define _rep3(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,_rep3,_rep2,)(__VA_ARGS__)
#define _rrep2(i,n) _rrep3(i,0,n)
#define _rrep3(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define rrep(...) _overload3(__VA_ARGS__,_rrep3,_rrep2,)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define bit(n) (1LL<<(n))
#define sz(x) ((int)(x).size())
#define fst first
#define snd second
using ll=long long;using pii=pair<int,int>;using vb=vector<bool>;
using vi=vector<int>;using vvi=vector<vi>;using vvvi=vector<vvi>;
using vl=vector<ll>;using vvl=vector<vl>;using vvvl=vector<vvl>;
using vd=vector<double>;using vvd=vector<vd>;using vvvd=vector<vvd>;
using vpii=vector<pii>;using vvpii=vector<vpii>;using vvvpii=vector<vvpii>;
template <typename T> T read() {T t; cin >> t; return t;}

void Main() {
  int h = read<int>();
  int w = read<int>();

  vector<string> B(h);
  rep(i, h) B[i] = read<string>();

  int cnt = 0;

  rep(y, h) rep(x, w) {
    if (B[y][x] == '#') cnt++;
  }

  if (cnt == h + w - 1) {
    cout << "Possible" << endl;
  }
  else {
    cout << "Impossible" << endl;
  }

}
int main() { cin.tie(nullptr); ios::sync_with_stdio(false); Main(); return 0; }
