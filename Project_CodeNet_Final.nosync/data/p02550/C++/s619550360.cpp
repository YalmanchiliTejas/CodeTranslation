#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define pb push_back
const int maxn = 10000;
const int INF32 = 1'050'000'000;
const long long INF64 = 4'000'000'000'000'000'000;
const int MOD7 = 1'000'000'007;
const int MOD9 = 1'000'000'009;
const int mod = MOD7;

void ERROR(int num) { cout << "ERROR" << num << endl; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[8]={-1,0,1,0,1,1,-1,-1};
int dy[8]={0,-1,0,1,1,-1,1,-1};


int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//input
	ll N, X, M;
	cin >> N >> X >> M;
	//calculate
	vector<ll> memo(M,-1);
	vector<ll> A;
	ll len = 0;
	ll total = 0;
	while(memo[X]==-1){
		A.pb(X);
		memo[X] = len;
		len++;
		total += X;
		X = (X*X)%M;
	}

	//calculate one circulation total
	ll c = len - memo[X];
	ll c_total = 0;
	for(int i = memo[X]; i < len; i++){
		c_total += A[i];
	}

	ll ans = 0;
	if(len > N){
		rep(i,N) ans += A[i];
	}else{
		// brefore circulaton total
		ans = total;
		// circulation total
		N -= len;
		ans += c_total*(N/c);
		// after circulation total
		N %= c;
		rep(i,N) ans += A[memo[X]+i];
	}

	cout << ans << endl;
}	