#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n",(x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define isYes(x) printf("%s\n",(x) ? "Yes" : "No")
#define isIn(x,y,h,w) (x >= 0 && x < h && y >= 0 && y < w)

#define int long long
//using ll = long long;
using P = pair<int,int>;

ostream &operator<<(ostream &os,const P &p){ return os << "(" << p.first << "," << p.second << ")"; }
template<class T>
ostream &operator<<(ostream &os,const vector<T> &v){
	for(int i = 0;i < v.size();i++) os << (i ? "," : "[") << v[i];
	os << "]";
	return os;
}

template<class T> T &chmin(T &a,const T &b){ return a = min(a,b); }
template<class T> T &chmax(T &a,const T &b){ return a = max(a,b); }

const int INF=1e+18;
const double EPS=1e-9;
const int MOD=998244353;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

template<long long mod = 1000000007>
struct modint{
	long long a;

	modint() : a(0){}
	modint(long long t){
		a = t % mod;
		if(a < 0) a += mod;
	}

	operator long long() const{ return a; }

	bool operator==(const modint &x) const{ return a == x.a; }
	bool operator!=(const modint &x) const{ return a != x.a; }

	modint operator-() const{ return modint(a ? (mod - a) : 0); }
	modint operator~() const{ return pow(mod - 2); }

	modint operator+(const modint &x) const{ return modint(*this) += x; }
	modint operator-(const modint &x) const{ return modint(*this) -= x; }
	modint operator*(const modint &x) const{ return modint(*this) *= x; }
	modint operator/(const modint &x) const{ return modint(*this) /= x; }

	modint &operator+=(const modint &x){
		a += x.a;
		if(a >= mod) a -= mod;
		return *this;
	}
	modint &operator-=(const modint &x){
		a -= x.a;
		if(a < 0) a += mod;
		return *this;
	}
	modint &operator*=(const modint &x){
		a = a * x.a % mod;
		return *this;
	}
	modint &operator/=(const modint &x){
		a = a * (~x).a % mod; 
		return *this;
	}

	friend ostream &operator<<(ostream &os,const modint &x){
		return os << x.a;
	}
	friend istream &operator>>(istream &is,modint &x){
		long long t;
		is >> t;
		x = modint(t);
		return is;
	}

	modint pow(long long x) const{
		modint ret = 1,tmp = a;
		for(;x;tmp *= tmp,x >>= 1){
			if(x & 1) ret *= tmp;
		}
		return ret;
	}
};

signed main(){
	int n,s,a[3010];
	modint<MOD> dp[3010][3010][3],ans = 0;
	cin >> n >> s;
	for(int i = 0;i < n;i++) cin >> a[i];
	dp[0][0][0] = 1;
	for(int i = 0;i < n;i++){
		for(int j = 0;j <= s;j++){
			for(int k = 0;k < 3;k++){
				dp[i + 1][j][k] += dp[i][j][k];
				if(k == 1 && j + a[i] <= s) dp[i + 1][j + a[i]][k] += dp[i][j][k];
				if(k != 2){
					dp[i + 1][j][k + 1] += dp[i][j][k];
					if(j + a[i] <= s) dp[i + 1][j + a[i]][k + 1] += dp[i][j][k];
				}
				if(k == 0){
					dp[i + 1][j][2] += dp[i][j][k];
					if(j + a[i] <= s) dp[i + 1][j + a[i]][2] += dp[i][j][k];
				}
			}
		}
	}
	cout << dp[n][s][2] << endl;
}
