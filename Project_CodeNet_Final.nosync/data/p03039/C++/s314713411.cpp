#include <bits/stdc++.h>
using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;
#define what_is_v(x) cerr << #x << " is "; for(auto&e: (x)) cerr << e << ' '; cerr << '\n'; //vector, set
#define what_is_a(x, n) cerr << #x << " is "; for(int i=0;i<n;i++) cerr << x[i] << ' '; cerr <<  '\n'; //n first element of array
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define st first
#define nd second
#define cerr_pair(x) '{' << x.st << ", " << x.nd << '}'
#define pwhat_is(x) cerr << #x << " is " << cerr_pair(x) << endl;
#define pwhat_is_v(x) cerr << #x << " is "; for(auto&e: (x)) cerr << cerr_pair(e) << ' '; cerr << '\n'; //vector, set
#define pwhat_is_a(x, n) cerr << #x << " is "; for(int i=0;i<n;i++) cerr << cerr_pair(x[i]) << ' '; cerr <<  '\n'; //n first element of array
#define endl '\n'
#define int long long

typedef pair<int,int> pii;
const int N = 2e5+5;
const int INF = 1e9;
const int MOD = 1e9+7;

int n, m, k;
int d;
int fact[N], r[N], rfact[N];
void init(){
	r[1] = 1;
	for(int i=2; i<N; i++){
		r[i] = MOD - (MOD/i)*r[MOD%i]%MOD;
	}
	fact[0] = rfact[0] = 1;
	for(int i=1; i<N; i++){
		fact[i] = fact[i-1]*i % MOD;
		rfact[i] = rfact[i-1]*r[i] % MOD;
	}
}
int C(int n, int k){
	if (n<0 || k<0 || k>n) return 0LL;
	return fact[n]*rfact[k] % MOD * rfact[n-k] % MOD;
}
int32_t main()
{
	IOS
	// freopen("input.txt", "r", stdin);
	cin >> n >> m >> k;
	//calculate sum of all pairs manhatan distance
	int dx = 0, dy = 0;
	for(int i=1; i<n; i++){
		dx = (dx + i*(i+1)/2*m % MOD * m) % MOD;
	}
	for(int j=1; j<m; j++){
		dy = (dy + j*(j+1)/2*n % MOD *n) % MOD;
	}
	init();
	d = (dx + dy) % MOD;

	int ans = C(n*m-2, k-2)* d % MOD;
	cout << ans << endl;
	
	return 0;
}
