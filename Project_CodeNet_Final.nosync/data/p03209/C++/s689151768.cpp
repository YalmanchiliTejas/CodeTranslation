#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define INF 999999999
#define m0(x) memset(x,0,sizeof(x))
#define fill(x,y) memset(x,y,sizeof(x))


using namespace std;


int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int dxx[8] = { 0,0,1,1,1,-1,-1,-1 };
int dyy[8] = { 1,-1,0,1,-1,0,1,-1 };




ll gcd(ll x, ll y) {
	ll m = max(x, y), n = min(x, y);
	if (m%n == 0)return n;
	else return gcd(m%n, n);
}
ll lcm(ll x, ll y) {
	return x / gcd(x, y)*y;
}

ll myPow(ll x, ll n, ll m) {
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return myPow(x * x % m, n / 2, m);
	else
		return x * myPow(x, n - 1, m) % m;
}

ll pow2(int a, int n) {//aのn乗を計算します。
	int x = 1;
	while (n > 0) {//全てのbitが捨てられるまで。
		if (n & 1) {//1番右のbitが1のとき。
			x = x * a;
		}
		a = a * a;
		n >>= 1;//bit全体を右に1つシフトして一番右を捨てる。
	}
	return x;
}

long long nCr(int n, int r) {
	if (r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
	long long ans = 1;
	int i;

	for (i = 1; i <= r; i++) {
		ans *= n - r + i;
		ans /= i;
	}

	return ans;
}


const int MOD = 1000000007;

ll layer[51];
ll all_pate[51];
ll pate(int n,ll k){
	if(n==0){
		if(k==0)return 0;
		else return 1;
	}
	if(k==0)return 0;
	if(k==layer[n]){
		return all_pate[n];
	}
	if(k<=layer[n-1]+1){
		return pate(n-1,k-1);
	}
	else if(k==layer[n-1]+2){
		return all_pate[n-1]+1;
	}
	else if(k>=layer[n-1]+3){
		ll dif=k-layer[n-1]-2;
		return all_pate[n-1]+1+pate(n-1,dif);
	}
}
int main() {
	layer[0]=1;
	all_pate[0]=1;
	FOR(i,1,51){
		layer[i]=2*layer[i-1]+3;
		all_pate[i]=all_pate[i-1]*2+1;
	}
	int N;
	ll K;
	cin>>N>>K;
	ll ans=pate(N,K);
	cout<<ans<<endl;
}