#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)
#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)
#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

/*
f(n) = n人のグループ分けの場合の数
f(n,m) = n人をm人以下のグループに分ける場合の数
a<=i<=b人グループがc<=x<=d個
*/

template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) { }
	ModInt(signed sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

	ModInt inverse() const {
		signed a = x, b = MOD, u = 1, v = 0;
		while (b) {
			signed t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		if (u < 0) u += Mod;
		ModInt res; res.x = (unsigned)u;
		return res;
	}
};
typedef ModInt<1000000007> mint;
vector<mint> fact, factinv;
void nCr_computeFactinv(int N) {
	N = min(N, mint::Mod - 1);
	fact.resize(N + 1); factinv.resize(N + 1);
	fact[0] = 1;
	reg(i, 1, N) fact[i] = fact[i - 1] * i;
	factinv[N] = fact[N].inverse();
	for (int i = N; i >= 1; i --) factinv[i - 1] = factinv[i] * i;
}
mint nCr(int n, int r) {
	if (n >= mint::Mod)
		return nCr(n % mint::Mod, r % mint::Mod) * nCr(n / mint::Mod, r / mint::Mod);
	return r > n ? 0 : fact[n] * factinv[n - r] * factinv[r];
}
mint nPr(int n, int r) {
	if (r<0)return 0;
	return r > n ? 0 : fact[n] * factinv[n-r];
}
mint nHr(int n, int r) { return r == 0 ? 1 : nCr(n + r - 1, r); }


ll n,a,b,c,d;
mint ans,dp[1010],dp2[1010];

void init(){
	cin>>n>>a>>b>>c>>d;
	nCr_computeFactinv(n);
	dp[n]=1;
}

int main(void){
	init();
	ireg(i,a,b){
		reg(m,0,n)dp2[m]=0;
		reg(m,0,n){  // 残り人数
			mint tmp=1;
			rep(x,c)tmp*=factinv[i];
			dp2[m]+=dp[m];  // x=0
			reg(x,c,d){  // 大きさiのグループの人数
				if(m-i*x<0)break;
				dp2[m-i*x]+=dp[m]*fact[m]*factinv[m-i*x]*factinv[x]*tmp;
				tmp*=factinv[i];
			}
		}
		reg(m,0,n)dp[m]=dp2[m];
		// reg(m,0,n)cerr<<dp[m].get()<<" ";
		// cerr<<endl;
	}
	cout<<dp[0].get()<<endl;
	return 0;
}