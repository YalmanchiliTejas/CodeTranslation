#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cmath>
#include<assert.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define INF 0x3f3f3f3f
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
const ll mod=998244353;
const double PI = acos(-1.0);
const double epsilon = PI / 180.0;//角度转弧度 
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
const int N = 2e5+10, M = 1e6+10;
map<ll, int> _hash;
int main() {
	ll n, x, m;
	cin>>n>>x>>m;
	ll ans = 0;
	vector<ll> v;
	v.pb(0);
	for(int i = 1;i <= n;i++) {
		if(_hash[x]) {
			int l = _hash[x], r = i - 1;
			ll tmp = v[r] - v[l - 1];
			ans += (n - r) / (r - l + 1) * tmp;
			int t = (n - r) % (r - l + 1);
			ans += v[(t + l - 1)] - v[l - 1];
			break;
		}
		v.pb(x);
		v[SZ(v) - 1] += v[SZ(v) - 2];
		_hash[x] = i;
		ans += x;
		x = x * x % m;
	}
	cout<<ans;
	return 0;
}