#include<bits/stdc++.h>
#define maxn 32005
#define int long long
using namespace std;
typedef long long ll;
typedef long long LL;
const LL mod = 998244353;
int n, m;
const int g = 3;
LL dp[505][maxn];
ll fac[maxn];
ll invv[maxn];
LL qpower(LL, LL);
LL inline inv(LL x) {
	return qpower(x, mod - 2);
}
ll qpow(long long a,long long b) {
	ll ans=1;
	ll k=a;
	while(b) {
		if(b&1)ans=ans*k%mod;
		k=k*k%mod;
		b>>=1;
	}
	return (ans+mod)%mod;
}
void init() {
	long long it;
	fac[0]=1;
	invv[0]=1;
	fac[1]=1;
	invv[1]=1;
	for (it=2; it<maxn; it++) {
		fac[it]=((fac[it-1]*it)%mod+mod)%mod;
		invv[it]=(qpow(fac[it],mod-2)+mod)%mod;
	}
}
ll C(ll n,ll m) {
	if (n<m||m<0) return 0;
	return  (fac[n]*invv[m]%mod*invv[n-m]%mod+mod)%mod;
}
void NTT(LL *, int, int);
ll p[maxn], q[maxn];
void solve(int index) {
	for(int i=0; i<=n; i++) {
		dp[index][i]+=dp[index-1][i]*(1+C(i+1, 2))%mod;
		dp[index][i]%=mod;
	}
	memset(p,0,sizeof(p)), memset(q,0,sizeof(q));
	for(int i=1; i<=n; i++) q[i] = invv[i+2];
	for(int i=0; i<=n; i++) p[i] = dp[index-1][i]*invv[i]%mod;
	int len = 1;
	while(len<(2*(n+1))) len<<=1;
	NTT(p, len, 1);
	NTT(q, len, 1);
	for (int i = 0; i < len; ++i)
		p[i] = p[i] * q[i] % mod;
	NTT(p, len, -1);
	for(int i=1; i<=n; i++) {
		dp[index][i]+=p[i]*fac[i+2]%mod;
		dp[index][i]%=mod;
	}
}
signed main() {
	std::cin >> n >> m;
	init();
	dp[0][0] = 1;
	for(int i=1; i<=m; i++) {
		solve(i);
	}
	ll ans = 0;
	for(int i=0;i<=n;i++) {
		ans += dp[m][i]*C(n, i)%mod;
		ans%=mod;
	
	}
	cout << ans << endl;

}
LL qpower(LL x, LL y) {
	LL res = 1;
	while (y) {
		if (y & 1) (res *= x) %= mod;
		(x *= x) %= mod;
		y >>= 1;
	}
	return res;
}
void NTT(LL *arr, int size, int type) {
	int rev[100005];
	rev[0] = 0;
	for (int i = 1; i < size; ++i)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (size >> 1) : 0);
	for (int i = 0; i < size; ++i)
		if (rev[i] > i) std::swap(arr[i], arr[rev[i]]);
	for (int len = 2; len <= size; len <<= 1) {
		LL wn = qpower(g, (mod - 1) / len);
		if (type == -1) wn = inv(wn);
		for (int i = 0; i < size; i += len) {
			LL w = 1;
			for (int j = 0; j < (len >> 1); ++j, w = w * wn % mod) {
				LL tmp1 = arr[i + j], tmp2 = arr[i + (len >> 1) + j] * w % mod;
				arr[i + j] = tmp1 + tmp2;
				arr[i + j + (len >> 1)] = tmp1 - tmp2;
				if (arr[i + j] >= mod) arr[i + j] -= mod;
				if (arr[i + j + (len >> 1)] < 0) arr[i + j + (len >> 1)] += mod;
			}
		}
	}
	if (type == -1) {
		LL t = inv(size);
		for (int i = 0; i < size; ++i)
			arr[i] = arr[i] * t % mod;
	}
}
