#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
//const ull mod = 1e9 + 7;
const ll mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

// debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class S, class T> ostream& operator << (ostream& os, const pair<S, T> v){
  os << "(" << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator << (ostream& os, const vector<T> v){
  for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator << (ostream& os, const vector<vector<T>> v){
  for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

// conversion number to bit
string num2bit(ll num, ll len){
  string bit = "";
  REP(i, len){
    bit += char('0'+(num>>i & 1));
  }
  return bit;
}

ll dp[105][2][5];

string N;
ll K;

ll rec(ll idx, bool tight, ll kosu){
	if(kosu<0) return 0;
	if(dp[idx][tight][kosu]>=0) return dp[idx][tight][kosu];
	if(idx == (int)N.size()){
		return (kosu==0 ? 1 : 0);
	}

	ll res = 0;
	ll ub = (tight ? N[idx]-'0' : 9);
	for(int i=0;i<=ub;i++){
		bool flag = (i==ub ? tight : false);
		ll kn = kosu - (i==0 ? 0 : 1);
		res += rec(idx+1, flag, kn);
	}
	dp[idx][tight][kosu] = res;
	return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> K;

    REP(i, 105) REP(j, 2) REP(k, 5) dp[i][j][k] = -1;

    cout << rec(0, true, K) << endl;

    return 0;
}