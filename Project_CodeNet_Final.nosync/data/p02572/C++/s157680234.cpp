#include <bits/stdc++.h>
#define F(i,a,b) for(ll i=a;i<=(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define maxnkp make_pair
#define fi first
#define se second
#define eps 1e-7
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
const int mods = 1e9+7;
const int maxn = 2e5+10;
const int N = 1e5+10;
const int E = 1e6+10; 

int n;
ll a[maxn];
ll suf[maxn];

int main(){
	cin>>n;
	F(i,1,n) cin>>a[i];
	suf[n] = a[n];
	dF(i,n-1,1){
		suf[i] = suf[i+1]+a[i];
		suf[i]%=mods;
	}
	ll ans = 0;
	F(i,1,n){
		ans+= a[i]*suf[i+1]%mods;
		ans%=mods;
	}
	cout<<ans<<endl;
}