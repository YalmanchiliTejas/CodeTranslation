#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
using mat = vector<vector<ll>>;

inline void IOS() { ios::sync_with_stdio(false), cin.tie(0); }

template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
	fill((T *)array, (T *)(array + N), val);
}

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//ll pas[5001][5002];

ll dp[114514][2][102] = {};
ll d, n;
string k;

ll rec(ll i, bool t, ll sum){
	
	if(i == n)return (sum % d == 0);

	ll &tmp = dp[i][t][sum];
	if(~tmp)return tmp;

	
	int keta = k[i] - '0';
	int m = (t ? keta : 9);

	tmp = 0;
	for (int j = 0;j <= m;++j) {
		tmp += rec(i + 1,t && j == m,(sum + j) % d);
		tmp %= MOD;
	}
	return tmp;
}

signed main(){
	IOS();
	cin >> k >> d;
	Fill(dp, -1);
	n = k.size();
	if(n <= 3 && stol(k) < d){
		cout << 0 << endl;
		return 0;
	}
	ll ans = rec(0, true, 0) + MOD - 1;
	ans %= MOD;
	cout << ans << endl;	
}