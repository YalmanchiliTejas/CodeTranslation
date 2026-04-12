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

const ll INF = (1ll<<60);
ll dp[3030][3030];
vector<ll> a(3030);
ll N;

ll rec(ll L, ll R){
	if(dp[L][R]>-INF) return dp[L][R];
	if(L==R) return 0;

	ll res;
	if((R-L)%2 == N%2){
		// taro
		res = -INF;
		res = max(res, rec(L+1, R)+a[L]);
		res = max(res, rec(L, R-1)+a[R-1]);
	}else{
		// jiro
		res = INF;
		res = min(res, rec(L+1, R)-a[L]);
		res = min(res, rec(L, R-1)-a[R-1]);
	}

	dp[L][R] = res;
	return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    REP(i, 3030)REP(j, 3030) dp[i][j] = -INF;

    cin >> N;
    REP(i, N) cin >> a[i];

    cout << rec(0, N) << endl;
    return 0;
}