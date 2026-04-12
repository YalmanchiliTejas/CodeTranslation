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

ll dp[20][550000];
ll N;
string S;

ll judge(ll x, ll y){
	if(x>y) swap(x, y);
	if(S[y-x-1]=='0'){
		return x;
	}else{
		return y;
	}
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    cin >> S;
    ll M = (1ll<<N);
    vector<ll> P(M);
    REP(i, M) cin >> P[i];

    vector<ll> Q(2*M);
    REP(i, M){
    	Q[i] = P[i];
    	Q[i+M] = P[i];
    }

    REP(i, 2*M) dp[0][i] = Q[i];
    for(int i=1;i<=N;i++){
    	ll len = (1ll<<(i-1));
    	for(int j=0;j+len<2*M;j++){
    		dp[i][j] = judge(dp[i-1][j], dp[i-1][j+len]);
    	}
    }

    REP(i, M){
    	cout << dp[N][i] << endl;
    }
    return 0;
}
