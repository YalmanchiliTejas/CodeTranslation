#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <cassert>
#define SIZE 100005
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define MOD 998244353

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

template<int mod, int primitive_root>
class NTT {
public:
	int get_mod() const { return mod; }
	void _ntt(vector<ll>& a, int sign) {
		const int n = sz(a);
		assert((n ^ (n&-n)) == 0); //n = 2^k

		const int g = 3; //g is primitive root of mod
		int h = (int)mod_pow(g, (mod - 1) / n, mod); // h^n = 1
		if (sign == -1) h = (int)mod_inv(h, mod); //h = h^-1 % mod

		//bit reverse
		int i = 0;
		for (int j = 1; j < n - 1; ++j) {
			for (int k = n >> 1; k >(i ^= k); k >>= 1);
			if (j < i) swap(a[i], a[j]);
		}

		for (int m = 1; m < n; m *= 2) {
			const int m2 = 2 * m;
			const ll base = mod_pow(h, n / m2, mod);
			ll w = 1;
			FOR(x, m) {
				for (int s = x; s < n; s += m2) {
					ll u = a[s];
					ll d = a[s + m] * w % mod;
					a[s] = u + d;
					if (a[s] >= mod) a[s] -= mod;
					a[s + m] = u - d;
					if (a[s + m] < 0) a[s + m] += mod;
				}
				w = w * base % mod;
			}
		}

		for (auto& x : a) if (x < 0) x += mod;
	}
	void ntt(vector<ll>& input) {
		_ntt(input, 1);
	}
	void intt(vector<ll>& input) {
		_ntt(input, -1);
		const int n_inv = mod_inv(sz(input), mod);
		for (auto& x : input) x = x * n_inv % mod;
	}

	// 畳み込み演算を行う
	vector<ll> convolution(const vector<ll>& a, const vector<ll>& b){
		int ntt_size = 1;
		while (ntt_size < sz(a) + sz(b)) ntt_size *= 2;

		vector<ll> _a = a, _b = b;
		_a.resize(ntt_size); _b.resize(ntt_size);

		ntt(_a);
		ntt(_b);

		FOR(i, ntt_size){
			(_a[i] *= _b[i]) %= mod;
		}

		intt(_a);
		return _a;
	}
};
NTT <MOD,3> run;

ll inv[SIZE],fac[SIZE],finv[SIZE];
void make()
{
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
	inv[1]=1;
	for(int i=2;i<SIZE;i++)
	{
		inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
		fac[i]=fac[i-1]*(ll) i%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
}
ll C(int a,int b)
{
	if(a<b) return 0;
	return fac[a]*(finv[b]*finv[a-b]%MOD)%MOD;
}
char A[SIZE],B[SIZE];
ll dp1[SIZE];
int a,b;

void mpow(int t)
{
	if(t==0)
	{
		for(int i=0;i<=a+b;i++) dp1[i]=0;
		dp1[0]=1;
	}
	else
	{
		mpow(t/2);
		vector <ll> A;
		for(int i=0;i<=a+b;i++) A.push_back(dp1[i]);
		vector <ll> B=run.convolution(A,A);
		for(int i=0;i<=a+b;i++) dp1[i]=B[i];
		if(t%2==1)
		{
			vector <ll> C;
			for(int i=0;i<=a+b;i++) C.push_back(finv[i]);
			C[0]=0;
			for(int i=0;i<=a+b;i++) A[i]=dp1[i];
			B=run.convolution(A,C);
			for(int i=0;i<=a+b;i++) dp1[i]=B[i];
		}
	}
}
int main()
{
	make();
	scanf("%s",&A);
	scanf("%s",&B);
	int n=strlen(A);
	a=0,b=0;
	for(int i=0;i<n;i++)
	{
		if(A[i]=='1')
		{
			if(B[i]=='1') b++;
			else a++;
		}
	}
	//printf("* %d %d\n",a,b);
	mpow(a);
	ll ret=0;
	for(int i=a;i<=a+b;i++)
	{
		int zan=b-(i-a);
		ll way=C(b,zan);
		way=way*fac[zan]%MOD*fac[zan]%MOD;
		way=way*fac[i-a]%MOD*dp1[i]%MOD*fac[i]%MOD;
		way=way*C(i+zan,zan)%MOD;
		ret+=way;
		if(ret>=MOD) ret-=MOD;
		//printf("%d %lld\n",i,way);
	}
	printf("%lld\n",ret*fac[a]%MOD);
	return 0;
}
