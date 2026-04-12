#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0)
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ALL(x) (x).begin(), (x).end()
#define dump(x) cout << (x) << endl
#define LMAX 9223372036854775807LL
#define LMIN -9223372036854775807LL
using ll = long long;
template<typename T>
using vec = vector<T>;
using P = pair<ll, ll>;
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
	fill((T *)array, (T *)(array + N), val);
}

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//ll pas[51][52];
ll all[51];
ll p[51];

signed main(){
	IOS;
	ll n, x;
	cin >> n >> x;
	p[0] = 1;
	all[0] = 1;
	for(ll i = 1;i <= n;i++){
		p[i] = 2 * p[i - 1]  + 1;
		all[i] = 2 * all[i - 1] + 3;
	}
	ll ans = 0;
	for(int i = n - 1;i >= 0;i--){
		if(x == 1){
			break;
		}
		if(x == all[i] + 2){
			ans += (1 + p[i]);
			break;
		}
		else if(x == 2 * all[i] + 3){
			ans += 2 * p[i] + 1;
			break;
		}
		else if(x > all[i] + 2){
			ans += p[i] + 1;
			x -= all[i] + 2;
		}
		else {
			x--;
		}
		if(i == 0){
			ans++;
			break;
		}
	}
	dump(ans);
}	