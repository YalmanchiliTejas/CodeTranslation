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

LL dp[3010][3010];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  VL xs(N);
  cin >> xs;

  REP(i,N){
    dp[i][i+1] = (N % 2 ? 1 : -1) * xs[i];
  }

  for(int len=2;len<=N;++len){
    int turn = (N - len) % 2; // 0 -> L, 1 -> R
    for(int b=0,e=len;e<=N;++b,++e){
      if(turn == 0){ // L
        dp[b][e] = max(dp[b+1][e] + xs[b], dp[b][e-1] + xs[e-1]);
      }
      else{ // R
        dp[b][e] = min(dp[b+1][e] - xs[b], dp[b][e-1] - xs[e-1]);
      }
    }
  }

  cout << dp[0][N] << endl;

  return 0;
}
