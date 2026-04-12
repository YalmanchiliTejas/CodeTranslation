#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<pdd> vdd;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mem(a,b) memset(a, b, sizeof(a) )
#define all(x) (x).begin(),(x).end()
#define INF 1000000000000
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(){
	int n;cin>>n;
	vl a(n);
	rep(i,n)cin>>a[i];
	ll sum1[n+1],sum2[n+1];
    mem(sum1,0);
    mem(sum2,0);
	sum1[0]=a[0];sum2[0]=0;
	for(int i=1;i<n;++i){
		if(i%2==0){
			sum1[i]=sum1[i-1]+a[i];
			sum2[i]=sum2[i-1];
		}
		else{
			sum1[i]=sum1[i-1];
			sum2[i]=sum2[i-1]+a[i];
		}
	}
	ll dp[n][2];
	mem(dp,0);
	dp[0][0]=0;
	dp[0][1]=a[0];
	dp[1][0]=dp[0][1];
    dp[1][1]=dp[0][0]+a[1];
	if(n>=3){
	dp[2][0]=max(dp[1][0],dp[1][1]);
	dp[2][1]=dp[0][0]+a[2];
	for(int i=3;i<n;++i){
		if(i%2==0){
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
			dp[i][1]=max(dp[i-2][0],dp[i-2][1])+a[i];
		}
		if(i%2==1){
			dp[i][0]=dp[i-2][0]+a[i-1];
			dp[i][1]=dp[i-1][0]+a[i];
		}
	}
	}
	cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
}
