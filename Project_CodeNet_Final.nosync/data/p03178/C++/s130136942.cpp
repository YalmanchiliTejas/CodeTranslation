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

LL dp[10000+10][2][101];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string S;
  cin >> S;
  LL D;
  cin >> D;

  int N = SZ(S);
  dp[N][0][0] = dp[N][1][0] = 1;
  for(int i=N-1;i>=0;--i){
    int c = S[i] - '0';
    for(int dc=0;dc<10;++dc){
      for(int d=0;d<D;++d){
        (dp[i][1][(d+dc)%D] += dp[i+1][1][d]) %= MOD;
        if(dc == c) (dp[i][0][(d+dc)%D] += dp[i+1][0][d]) %= MOD;
        else if(dc < c) (dp[i][0][(d+dc)%D] += dp[i+1][1][d]) %= MOD;
      }
    }
  }

  cout << (MOD-1+dp[0][0][0])%MOD << endl;

  return 0;
}
