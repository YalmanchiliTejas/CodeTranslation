#include<bits/stdc++.h>
using namespace std;
#pragma region atcoder
#include <atcoder/segtree>
using namespace atcoder;
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
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
template<class T>bool chmax(T &a, const T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T b) { if (b<a) { a=b; return 1; } return 0; }
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a / gcd(a, b) * b;}
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
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int target;
int op(int a, int b){return max(a, b);}
int e(){return -1;}
bool f(int v){ return v < target;}

int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	int n, q; cin >> n >> q;
	vi a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	segtree<int, op, e> d(a);
	for(int i = 0; i < q; i++){
		int t; cin >> t;
		if(t == 1){
			int x, v; cin >> x >> v;
			x--;
			d.set(x, v);
		}
		if(t == 2){
			int l, r; cin >> l >> r;
			l--;
			cout << d.prod(l, r) << endl;
		}
		if(t == 3){
			int x; cin >> x >> target;
			x--;
			cout << d.max_right<f>(x) + 1 << endl;
		}
	}
} 
