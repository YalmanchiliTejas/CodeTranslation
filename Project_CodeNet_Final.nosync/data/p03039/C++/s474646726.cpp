#include<bits/stdc++.h>
using namespace std;
#pragma region atcoder
//using mint = modint998244353;
//These are for segment tree
/*int op(int a, int b){return max(a, b);}
int e(){return -1;}
bool f(int v){ return v < target;}
*/
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

template<class T>bool chmax(T &a, const T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T b) { if (b<a) { a=b; return 1; } return 0; }
ll modpow(ll a, ll p){ll ret = 1; while(p){if(p & 1){ret = ret * a % mod;} a = a * a % mod; p >>= 1;} return ret;}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

/*-----------------------------------------------------------------------------------------------------*/
ll fact[MAX], finv[MAX], inv[MAX];

void pre_cal(){
    fact[0] = fact[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++){
        fact[i] = fact[i-1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod; 
    }
}

ll nCk(ll n, ll k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fact[n] * finv[k] % mod * finv[n - k] % mod;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	pre_cal();
	ll n, m, k; cin >> n >> m >> k;
	ll ans = 0;
	vector<ll> x_num(m), y_num(n);
	for(ll i = 1; i <= m - 1; i++){
		x_num[i] = n * n % mod * (m - i) % mod * i % mod;
	}
	for(ll i = 1; i <= n - 1; i++){
		y_num[i] = m * m % mod * (n - i) % mod * i % mod;
	}
	for(ll i = 1; i <= m - 1; i++){
		ans += x_num[i] * nCk(n * m - 2, k - 2);
		ans %= mod;
		//debug(ans);
	}
	for(ll i = 1; i <= n - 1; i++){
		ans += y_num[i] * nCk(n * m - 2, k - 2);
		ans %= mod;
		//debug(ans);
	}
	cout << ans << endl;
}