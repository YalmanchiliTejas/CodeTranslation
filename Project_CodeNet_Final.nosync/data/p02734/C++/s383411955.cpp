#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin(), v.end()
bool chmin(ll & a, ll  b) { if (b < a) { a = b; return 1; } return 0; }
bool chmax(ll & a, ll b) { if (b > a) { a = b; return 1; } return 0; }
const ll INF = 999999999999999;
const ll MOD = 998244353;
const ll MAX_N=500010;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans;
#include <cstdint>                                                                                                              

template <std::uint_fast64_t Modulus> class modint {
	using u64 = std::uint_fast64_t;

public:
	u64 a;

	constexpr modint(const u64 x = 0) noexcept : a(x% Modulus) {}
	constexpr u64& value() noexcept { return a; }
	constexpr const u64& value() const noexcept { return a; }
	constexpr modint operator+(const modint rhs) const noexcept {
		return modint(*this) += rhs;
	}
	constexpr modint operator-(const modint rhs) const noexcept {
		return modint(*this) -= rhs;
	}
	constexpr modint operator*(const modint rhs) const noexcept {
		return modint(*this) *= rhs;
	}
	constexpr modint operator/(const modint rhs) const noexcept {
		return modint(*this) /= rhs;
	}
	constexpr modint& operator+=(const modint rhs) noexcept {
		a += rhs.a;
		if (a >= Modulus) {
			a -= Modulus;
		}
		return *this;
	}
	constexpr modint& operator-=(const modint rhs) noexcept {
		if (a < rhs.a) {
			a += Modulus;
		}
		a -= rhs.a;
		return *this;
	}
	constexpr modint& operator*=(const modint rhs) noexcept {
		a = a * rhs.a % Modulus;
		return *this;
	}
	constexpr modint& operator/=(modint rhs) noexcept {
		u64 exp = Modulus - 2;
		while (exp) {
			if (exp % 2) {
				*this *= rhs;
			}
			rhs *= rhs;
			exp /= 2;
		}
		return *this;
	}
};

using mint = modint<MOD>;
int main() {
    cin >> n>>t;
    vl A;
    rep(i,n){
        cin>>x;
        A.push_back(x);
    }

    mint dp[n+1][t+1];

    rep(i,n+1){
        rep(j,t+1){
            dp[i][j]=0;
        }
    }

    rep(i,n+1){
        dp[i][0]=i+1;
    }

    rep(i,n+1){
        for(ll j=1;j<=t;j++){
            if(i>0&&j>0)dp[i][j]=dp[i-1][j];
            if(i>0&&j>=A[i-1])dp[i][j]+=dp[i-1][j-A[i-1]];
        }
    }
    
    /*rep(i,n+1){
    	rep(j,t+1){
    		cout<<i<<" "<<j<<" "<<dp[i][j].a<<endl;
    	}
    }*/

    mint ans=0;
    rep(i,n){
        ans+=(dp[i+1][t]-dp[i][t])*(n-i);
    }

    cout<<ans.a<<endl;
}