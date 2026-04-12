#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
using LL = long long;
using VL = vector<LL>;
using VVL = vector<VL>;
using PLL = pair<LL, LL>;
using VS = vector<string>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second

template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}
template<class T>
istream& operator>>(istream& is, vector<T>& xs){
  for(auto& x: xs)
	is >> x;
  return is;
}
template<class S, class T>
ostream& operator<<(ostream& os, const pair<S,T>& p){
  return os << p.FF << " " << p.SS;
}
template<class T>
ostream& operator<<(ostream& os, const vector<T>& xs){
  for(unsigned int i=0;i<xs.size();++i)
	os << (i?" ":"") << xs[i];
  return os;
}
template<class T>
void maxi(T& x, T y){
  if(x < y) x = y;
}
template<class T>
void mini(T& x, T y){
  if(x > y) x = y;
}
void debug(istringstream&){}
template <char sep=',', class Head, class... Tail>
void debug(istringstream& iss, Head&& head, Tail&&... tail)
{
  string name;
  getline(iss, name, ',');
  cerr << sep << name << "=" << head;
  debug(iss, forward<Tail>(tail)...);
}
#define DEBUG(...) \
  do{ \
    istringstream ss(#__VA_ARGS__); \
    debug<' '>(ss, __VA_ARGS__); \
    cerr<<endl; \
  }while(0)

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

LL cnt[60];
LL solve(LL N, LL X){
  if(X <= 0) return 0;
  if(N == 0){
    return X ? 1 : 0;
  }

  if(cnt[N] <= X) return solve(N-1, X) * 2 + 1;
  if(cnt[N-1] >= X-1) return solve(N-1, X-1);
  LL ans = solve(N-1, cnt[N-1]) + 1;
  if(X - 2 - cnt[N-1] > 0)
    ans += solve(N-1, X - 2 - cnt[N-1]);

  return ans;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  LL N, X;
  cin >> N >> X;

  cnt[0] = 1;
  for(int i=1;i<=N;++i){
    cnt[i] = cnt[i-1] * 2 + 3;
  }

  cout << solve(N, X) << endl;

  return 0;
}
