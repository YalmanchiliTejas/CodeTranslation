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



signed main(){
	IOS();
	ll n, sum, x;
	while(1){
		cin >> n;
		sum = 0;
		ll MAX = 0;
		ll MIN = 114514;
		if(n == 0)break;
		for (int i = 0;i < n;++i) {
			cin >> x;
			MAX = max(x, MAX);
			MIN = min(x, MIN);
			sum += x;
		}
		ll ans = floor((sum - MAX - MIN) / (double)(n - 2));
		cout << ans << endl;
	}

	return 0;
}
