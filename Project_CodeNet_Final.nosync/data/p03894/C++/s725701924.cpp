#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef pair<LL, LL> PLL;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, Q; cin >> N >> Q;
  int crt = 1;
  vector<bool> ok(N+2);
  ok[2] = true;
  REP(i,Q){
	int a, b; cin >> a >> b;
	swap(ok[a], ok[b]);
	if(crt == a) crt = b;
	else if(crt == b) crt = a;
	ok[crt-1] = ok[crt+1] = true;
  }
  ok[crt] = true;

  int ans = 0;
  FOR(i,1,N+1) ans += ok[i];
  cout << ans << endl;

  return 0;
}
