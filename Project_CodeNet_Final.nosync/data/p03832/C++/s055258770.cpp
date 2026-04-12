#include <bits/stdc++.h>
#define MOD 1000000007
int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
int64_t rll() {
	long long n;
	scanf("%lld", &n);
	return n;
}

template<int mod>
struct ModInt{
    int x;
    ModInt():x(0){}
    ModInt(long long y):x(y>=0?y%mod:(mod-(-y)%mod)%mod){}
    ModInt &operator+=(const ModInt &p){
        if((x+=p.x)>=mod)x-=mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &p){
        if((x+=mod-p.x)>=mod)x-=mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &p){
        x=(int)(1LL*x*p.x%mod);
        return *this;
    }
    ModInt &operator/=(const ModInt &p){
        *this*=p.inverse();
        return *this;
    }
	ModInt &operator^=(long long p){
		ModInt res = 1;
		for (; p; p >>= 1) {
			if (p & 1) res *= *this;
			*this *= *this;
		}
		return *this = res;
	}
    ModInt operator-()const{return ModInt(-x);}
    ModInt operator+(const ModInt &p)const{return ModInt(*this)+=p;}
    ModInt operator-(const ModInt &p)const{return ModInt(*this)-=p;}
    ModInt operator*(const ModInt &p)const{return ModInt(*this)*=p;}
    ModInt operator/(const ModInt &p)const{return ModInt(*this)/=p;}
	ModInt operator^(long long p)const{return ModInt(*this)^=p;}
    bool operator==(const ModInt &p)const{return x==p.x;}
    bool operator!=(const ModInt &p)const{return x!=p.x;}
    explicit operator int() const { return x; }                           // added by QCFium
    ModInt operator=(const int p) {x = p; return ModInt(*this);} // added by QCFium
    ModInt inverse()const{
        int a=x,b=mod,u=1,v=0,t;
        while(b>0){
            t=a/b;
            a-=t*b;
            std::swap(a,b);
            u-=t*v;
            std::swap(u,v);
        }
        return ModInt(u);
    }
    friend std::ostream &operator<<(std::ostream &os,const ModInt<mod> &p){
        return os<<p.x;
    }
    friend std::istream &operator>>(std::istream &is,ModInt<mod> &a){
        long long x;
        is>>x;
        a=ModInt<mod>(x);
        return (is);
    }
};
typedef ModInt<MOD> mint;

struct MComb {
    std::vector<mint> fact;
    std::vector<mint> inversed;
    MComb(int n) { // O(n+log(mod))
        fact = std::vector<mint>(n+1,1);
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1]*mint(i);
        inversed = std::vector<mint>(n+1);
        inversed[n] = fact[n] ^ (MOD-2);
        for (int i = n - 1; i >= 0; i--) inversed[i]=inversed[i+1]*mint(i+1);
    }
    mint ncr(int n, int r) {
        return (fact[n] * inversed[r] * inversed[n-r]);
    }
    mint npr(int n, int r) {
        return (fact[n] * inversed[n-r]);
    }
    mint nhr(int n, int r) {
        assert(n+r-1 < (int)fact.size());
        return ncr(n+r-1, r);
    }
};


int main() {
	int n = ri(), a = ri(), b = ri(), c = ri(), d = ri();
	std::vector<mint> dp[b - a + 1]; // [i][j] : i people left, until j is confirmed
	for (int i = a; i <= b; i++) dp[i - a].resize(n + 1);
	MComb com(1001);
	dp[0][n] = 1;
	for (int i = c; i <= d; i++) {
		if (i * a > n) break;
		dp[0][n - i * a] = mint(1) / (com.fact[a] ^ i) / com.fact[i];
	}
	for (int i = a + 1; i <= b; i++) { // i * ?
		// dp[i - a - 1] => dp[i - a]
		for (int j = 0; j <= n; j++) {
			// 0
			dp[i - a][j] += dp[i - a - 1][j];
			for (int k = c; k <= std::min(j / i, d); k++) { // i * k
				mint cur = dp[i - a - 1][j];
				dp[i - a][j - i * k] += cur / (com.fact[i] ^ k) / com.fact[k];
			}
		}
	}
	for (int i = a; i <= b; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i - a][j] *= com.fact[n];
			// std::cerr << i << " is confirmed, " << j << " people left : " << dp[i - a][j] << std::endl;
		}
	}
	std::cout << dp[b - a][0] << std::endl;
	
	return 0;
}
