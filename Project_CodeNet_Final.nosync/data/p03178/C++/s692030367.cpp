#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

//debug
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

ll dp[10005][10][2][105];
string K;
ll D;

ll rec(ll idx, ll val, ll tight, ll sum){
	if(dp[idx][val][tight][sum]>=0) return dp[idx][val][tight][sum];
	if(idx == (int)K.size()) return (sum==0);

	ll res = 0;
	ll ub = (tight ? (K[idx]-'0') : 9);
	for(int i=0;i<=ub;i++){
		ll flag;
		if(tight==1 && i==ub) flag = 1;
		else flag = 0;
		res += rec(idx+1, i, flag, (sum+i)%D);
		res %= mod;
	}

	dp[idx][val][tight][sum] = res;
	return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    REP(i, 10005)REP(j, 10)REP(k, 2)REP(l, 105) dp[i][j][k][l] = -1;

    cin >> K >> D;

    cout << (rec(0, 0, 1, 0)-1+mod)%mod << endl;
    return 0;
}