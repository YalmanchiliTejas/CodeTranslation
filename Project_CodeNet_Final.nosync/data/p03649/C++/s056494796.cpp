#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
ll n;
const int N=60;
ll a[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	rep(i,0,n) cin>>a[i];
	ll mx=LLONG_MAX;
	ll ans=0;
	while(mx>(n-1)) {
		ll act=0;
		rep(i,0,n) {
			act+=(a[i]-(n-1)+(n-1))/n;
		}
		ans+=act;
		rep(i,0,n) {
			ll cur=(a[i]-(n-1)+(n-1))/n;
			a[i]-=cur*n;
			a[i]+=(act-cur);
		}
		mx=0;
		rep(i,0,n) mx=max(mx,a[i]);
	}
	cout<<ans<<endl;
	return 0;
}