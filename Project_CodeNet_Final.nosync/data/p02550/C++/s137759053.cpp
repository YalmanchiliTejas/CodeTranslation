#include<bits/stdc++.h>
using namespace std;
#pragma region atcoder
//#include <atcoder/all>
//using namespace atcoder;
#pragma endregion
#pragma region macros
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vl = vector<ll>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rrep(i, n) for(int i = n - 1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#pragma endregion
#pragma region debug for var, v, vv
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){cout << endl;int cnt = 0;for(const auto& v : vv){cout << cnt << "th : "; view(v); cnt++;} cout << endl;}
#pragma endregion

const ll mod = 1000000007;
const int inf = 1001001001;
const ll INF = 1001001001001001001;
const int MAX = 2000005;

//using mint = modint998244353;
//These are for segment tree
/*int op(int a, int b){return max(a, b);}
int e(){return -1;}
bool f(int v){ return v < target;}
*/

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

template<class T>bool chmax(T &a, const T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T b) { if (b<a) { a=b; return 1; } return 0; }
ll modpow(ll a, ll p){ll ret = 1; while(p){if(p & 1){ret = ret * a % mod;} a = a * a % mod; p >>= 1;} return ret;}

/*--------------------------------------------------------------------------------------------------------------------------------*/

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, x, m; cin >> n >> x >> m;
	vl rem(1);
	vb done(m + 1, false);
	rem[0] = x;
	done[x] = true;
	ll now = x;
	for(int i = 0; i <= m; i++){
		now *= now;
		now %= m;
		if(done[now]){
			break;
		}
		done[now] = true;
		rem.push_back(now);
	}
	int rsz = rem.size();
	int roop;
	for(int i = 0; i < rsz; i++){
		if(rem[i] == now) roop = i;
	}
	ll ans = 0;
	if(now == 0){
		for(int i = 0; i < min((ll)rsz, n); i++){
			ans += rem[i];
		}
		cout << ans << endl;
	}
	else{
		n -= roop;
		ll cnt = 0; //循環和
		ll roop_size = rsz - roop;
		for(int i = 0; i < roop; i++) ans += rem[i];
		for(int i = roop; i < rsz; i++) cnt += rem[i];
		ll time = n / roop_size;
		ll res = n % roop_size;
		ans += time * cnt;
		for(int i = roop; i < roop + res; i++){
			ans += rem[i];
		}
		cout << ans << endl;
	}
} 
