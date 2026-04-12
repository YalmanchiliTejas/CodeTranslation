#include<bits/stdc++.h>
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
const ll mod= 998244353;
ll powmod(ll a,ll b) {
	ll res=1;
	a%=mod;
	assert(b>=0);
	for(; b; b>>=1) {
		if(b&1)res=res*a%mod;
		a=a*a%mod;
	}
	return res;
}
ll gcd(ll a,ll b) {
	return b?gcd(b,a%b):a;
}

const int N=3000+10;
int n,s,a[N],f[N];
ll ans=0;
int main() {
	cin>>n>>s;
	rep(i,1,n+1) {
		cin>>a[i];
	}
	rep(i,1,n+1) {
		per(j,a[i],s+1) {
			f[j]=((ll)f[j]+f[j-a[i]])%mod;

		}
		if(a[i]<=s) {
			f[a[i]]=(ll)(f[a[i]]+i)%mod;
		}
		ans=(ans+f[s])%mod;
	}
	cout<<ans;
	return 0;
}
