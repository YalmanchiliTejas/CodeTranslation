#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const int64_t LINF=8931145141919364364,LMOD=998244353;
// const int dy[]={0,-1,0,1,1,-1,-1,1};
// const int dx[]={1,0,-1,0,1,1,-1,-1};

using fint64 = int_fast64_t;
template<fint64 MOD>
struct ModInt {
	fint64 x;
	ModInt():x(0){}
	ModInt(fint64 x):
		x(x>=0?x%MOD:(MOD-(-x)%MOD)%MOD)
		{}
	// 負号
	ModInt operator -() const{
		return ModInt(-x);
	}
	// 加算
	ModInt &operator +=(const ModInt &rhs){
		x+=rhs.x;
		if(x>=MOD) x-=MOD;
		return (*this);
	}
	ModInt operator +(const ModInt &rhs) const{
		return ModInt(*this)+=rhs;
	}
	// 減算
	ModInt &operator -=(const ModInt &rhs){
		x+=MOD-rhs.x;
		if(x>=MOD) x-=MOD;
		return (*this);
	}
	ModInt operator -(const ModInt &rhs) const{
		return ModInt(*this)-=rhs;
	}
	// 乗算
	ModInt &operator *=(const ModInt &rhs){
		x*=rhs.x;
		if(x>=MOD) x%=MOD;
		return (*this);
	}
	ModInt operator *(const ModInt &rhs) const{
		return ModInt(*this)*=rhs;
	}
	// 除算
	ModInt &operator /=(const ModInt &rhs){
		(*this)*=rhs.inverse();
		return (*this);
	}
	ModInt operator /(const ModInt &rhs) const{
		return ModInt(*this)/=rhs;
	}
	// 等号
	bool operator ==(const ModInt &rhs){
		return x==rhs.x;
	}
	bool operator !=(const ModInt &rhs){
		return x!=rhs.x;
	}
	// 累乗
	ModInt pow(fint64 n) const{
		fint64 tmp=x;
		fint64 ret=1;
		while(n>0){
			if(n&1) ret=ret*tmp%MOD;
			tmp=tmp*tmp%MOD;
			n>>=1ll;
		}
		return ModInt(ret);
	}
	// 逆元
	ModInt inverse() const{
		fint64 a=x,b=MOD,s=1,t=0;
		while(b>0){
			fint64 u=a/b;
			a-=u*b;
			s-=u*t;
			swap(a,b);
			swap(s,t);
		}
		return ModInt(s);
	}
	// 入出力
	friend istream &operator >>(istream &lhs,ModInt<MOD> &rhs){
		fint64 x; lhs>>x;
		rhs=ModInt<MOD>(x);
		return lhs;
	}
	friend ostream &operator <<(ostream &lhs,const ModInt<MOD> &rhs){
		return lhs<<rhs.x;
	}
};

using mint = ModInt<LMOD>;
mint dp[3010][3010];
int main() {
	int n, s; cin >> n >> s;
	int a[n]; rep(i,n) cin >> a[i];
	dp[0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j <= s; ++j) {
			dp[i][j] += dp[i - 1][j];
			if(j - a[i - 1] >= 0) {
				if(j - a[i - 1] == 0) {
					if(j == s) {
						dp[i][j] += (dp[i - 1][j - a[i - 1]] + (i - 1)) * (n - i + 1);
					} else {
						dp[i][j] += dp[i - 1][j - a[i - 1]] + (i - 1);
					}
				} else {
					if(j == s) {
						dp[i][j] += dp[i - 1][j - a[i - 1]] * (n - i + 1);
					} else {
						dp[i][j] += dp[i - 1][j - a[i - 1]];
					}
				}
			}
		}
	}
	cout << dp[n][s] << '\n';
	return 0;
}