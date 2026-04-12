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

ll dp[10101][105][2];
string K;
ll D;

ll rec(ll i, ll sum, bool tight){
	if(dp[i][sum][tight]>=0) return dp[i][sum][tight];
	if(i==K.size()) return (sum%D==0);

	ll r = (tight?K[i]-'0':9);

	ll res = 0;
	for(int k=0;k<=r;k++){
		res += rec(i+1, (sum+k)%D, tight&&(k==r));
		res %= mod;
	}
	dp[i][sum][tight] = res;
	return res;
}

int main(){
	cin >> K >> D;
	memset(dp, -1, sizeof(dp));

	cout << (rec(0, 0, true) + mod - 1)%mod << endl;

    return 0;
}