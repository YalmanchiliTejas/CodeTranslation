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

string N;
ll K;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    ll M = N.size();
    ll dp[105][2][5] = {};
    dp[0][1][0] = 1;
    REP(i, M){
    	REP(k, 4){
    		REP(j, 10){
    			ll nk = k + (j!=0 ? 1 : 0);
	    		dp[i+1][0][nk] += dp[i][0][k];
	    		if(j<N[i]-'0')dp[i+1][0][nk] += dp[i][1][k];
	    		if(j==N[i]-'0')dp[i+1][1][nk] += dp[i][1][k];
	    	}
    	}
    }

    cout << dp[M][0][K] + dp[M][1][K] << endl;

    /*
    cout << dp[M][0][K] << endl;
    cout << dp[M][1][K] << endl;

    REP(j, 2){
	    REP(i, 10){
	    	REP(k, 5){
	    		cout << dp[i][j][k] << " ";
	    	}
	    	cout << endl;
	    }
	    cout << endl;
	}
	*/
    return 0;
}