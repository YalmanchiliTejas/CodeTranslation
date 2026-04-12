#include<bits/stdc++.h>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define rrep(i,a) for(int i=(int)a-1;i>=0;--i)
#define REP(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RREP(i,a,b) for(int i=(int)a-1;i>=b;--i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


ll gcd(ll n, ll m) {
    ll tmp;
    while (m!=0) {
        tmp = n % m;
        n = m;
        m = tmp;
    }
    return n;
}
 
ll lcm(ll n, ll m) {
    return abs(n) / gcd(n, m)*abs(m);//gl=xy
}

using namespace std;

template<int mod>
struct Modint{
    int x;
    Modint():x(0){}
    Modint(int64_t y):x((y%mod+mod)%mod){}

    Modint &operator+=(const Modint &p){
			if((x+=p.x)>=mod)
				x -= mod;
			return *this;
		}

		Modint &operator-=(const Modint &p){
			if((x+=mod-p.x)>=mod)
				x -= mod;
			return *this;
		}

		Modint &operator*=(const Modint &p){
			x = (1LL * x * p.x) % mod;
			return *this;
		}

		Modint &operator/=(const Modint &p){
			*this *= p.inverse();
			return *this;
		}

		Modint operator-() const { return Modint(-x); }
		Modint operator+(const Modint &p) const{
			return Modint(*this) += p;
		}
		Modint operator-(const Modint &p) const{
			return Modint(*this) -= p;
		}
		Modint operator*(const Modint &p) const{
			return Modint(*this) *= p;
		}
		Modint operator/(const Modint &p) const{
			return Modint(*this) /= p;
		}

		bool operator==(const Modint &p) const { return x == p.x; }
		bool operator!=(const Modint &p) const{return x != p.x;}

		Modint inverse() const{//非再帰拡張ユークリッド
			int a = x, b = mod, u = 1, v = 0;
			while(b>0){
				int t = a / b;
				swap(a -= t * b, b);
				swap(u -= t * v, v);
			}
			return Modint(u);
		}

		Modint pow(int64_t n) const{//繰り返し二乗法
			Modint ret(1), mul(x);
			while(n>0){
				if(n&1)
					ret *= mul;
				mul *= mul;
				n >>= 1;
			}
			return ret;
		}

		friend ostream &operator<<(ostream &os,const Modint &p){
			return os << p.x;
		}
};

using modint = Modint<mod>;

Modint<998244353> dp[3005][3005][3];

void solve()
{
	ll n, s;
	cin >> n >> s;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	for (ll i = 0; i < n;++i)
	{
		rep(j,s+1){
			if(j-a[i]>=0){
				dp[i + 1][j][1] += dp[i][j - a[i]][0]*(i+1);
				dp[i + 1][j][1] += dp[i][j - a[i]][1];
				dp[i + 1][j][2] += dp[i][j - a[i]][1] * (n - i);
				dp[i + 1][j][2] += dp[i][j - a[i]][0]* (i + 1) * (n - i);
			}
			dp[i + 1][j][0] += dp[i][j][0];
			dp[i + 1][j][1] += dp[i][j][1];
			dp[i + 1][j][2] += dp[i][j][2];
		}
	}
	cout << dp[n][s][2];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);
    solve();
    return 0;
}