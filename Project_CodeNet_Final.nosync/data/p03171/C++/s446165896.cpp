#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) { return a/gcd(a,b)*b;}
// head
const int mxN = 3e3+3;
int n;
ll dp[mxN][mxN], a[mxN];
int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	cin >> n;
	rep(i, 0, n) cin >> a[i];
	rep(len, 1, n + 1){
		rep(l, 0, n){
			int r = l + len - 1;
			if(r >= n) break;
			if(l == r) {
				dp[l][r] = a[l];
			}
			dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
		}
	}
	cout << dp[0][n-1] << endl;
}


