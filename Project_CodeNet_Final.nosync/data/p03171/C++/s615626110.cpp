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

template < typename T >
void vprint(T &v){
	REP(i, v.size()){
		cout << v[i] << " ";
	}
	cout << endl;
}

ll dp[3005][3005];
ll N;
ll a[3030];
ll INF = LLONG_MAX/2;

ll rec(ll i, ll j){
	//cout << i << " " << j << endl;
	if(dp[i][j]>-INF) return dp[i][j];
	if((j-i+1)%2==N%2){
		if(i==j){
			return a[i];
		}else{
			ll cand1 = rec(i+1, j) + a[i];
			ll cand2 = rec(i, j-1) + a[j];
			ll res = max(cand1, cand2);
			dp[i][j] = res;
			return res;
		}
	}else{
		if(i==j){
			return -a[i];
		}else{
			ll cand1 = rec(i+1, j) - a[i];
			ll cand2 = rec(i, j-1) - a[j];
			ll res = min(cand1, cand2);
			dp[i][j] = res;
			return res;
		}
	}
}

int main(){
	cin >> N;
	REP(i, N) cin >> a[i];

	REP(i, 3005)REP(j, 3005) dp[i][j] = -INF;

	cout << rec(0, N-1) << endl;

    return 0;
}