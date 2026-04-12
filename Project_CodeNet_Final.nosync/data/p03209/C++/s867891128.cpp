#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP0(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define RREP0(i,n) for(int i=n-1; i>=0; --i)
#define RREP1(i,n) for(int i=n; i>=1; --i)

#define SORT(c) sort((c).begin(),(c).end())
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define CLR(a) memset((a), 0 ,sizeof(a))

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
int gcd(int a,int b){return b?gcd(b,a%b):a;}

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;

const int INTINF = 2147483647;
const LL LLINF = 9223372036854775807;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;
const int MAX = 10001;

struct init{
    init(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
} init;

LL N,X;
std::vector<LL> layerL;
std::vector<LL> patyL;

void input(){
  std::cin >> N >> X;
  layerL.reserve(N+1); layerL[0] = 1;
  patyL.reserve(N+1); patyL[0] = 1;
  REP1(i,N){
    layerL[i] = layerL[i-1]*2+3;
    patyL[i] = patyL[i-1]*2+1;
  }
}


LL rec(LL N, LL X){
  if (N==0) {
    return (X<=0) ? 0 : 1 ;
  }else if ( X <= 1 + layerL[N-1] ){
    // (最下部バン+下のN-1バーガーを食べきれない)場合
    // N-1バーガーから X - |最下部バン| 枚を食べる
    return rec(N-1, X-1);
  }else {
    // 下のN-1パティと, 上のN-1パティの中から
    // X - |N-1バーガー1個分| - |最下部バン&中間パティ| 枚
    return patyL[N-1] + 1 + rec(N-1, X-2-layerL[N-1]);
  }
}

void solve(){
  LL ans = rec(N, X);
  std::cout << ans << '\n';
}


int main(int argc, char const *argv[]) {
  input();
  solve();

  return 0;
}
