#include <bits/stdc++.h>
#define INF 1000000007
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define print(x) cout << x << "\n"
#define print2(x, y) cout << x << " " << y << "\n"
#define printv(vec) rep(lp, vec.size()) cout << vec[lp] << " "; print(""); 
#define ALL(v) v.begin(), v.end()
#define SUM(v) accumulate(ALL(v), 0)
#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define SORT(v) sort(ALL(v))
#define REV(v) reverse(ALL(v))
typedef long long ll;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vs = vector<string>;

const int mod = 1000000007;
class mint {
public:
    ll x;
    mint(ll x = 0) : x((x % mod + mod) % mod) {}
    mint operator-() const { 
      return mint(-x);
    }
    mint& operator+=(const mint& a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint& a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const  mint& a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint& a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint& a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint& a) const {
        mint res(*this);
        return res *= a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }
    mint inv() const {
        return pow(mod - 2);
    }
    mint& operator/=(const mint& a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint& a) const {
        mint res(*this);
        return res /= a;
    }
    friend ostream& operator<<(ostream& os, const mint& m){
        os << m.x;
        return os;
    }
};

ll modpow(ll a, ll n){
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

void Main(){
	
	string S;
	ll K;
	cin >> S >> K;
	
	ll dp[110][2][4] = {0};
	// dp[i][j][k]
	// i: 上位 bit
	// j: tight
	// k: 0でない数字の個数
	dp[0][1][0] = 1;
	rep(i, 100) rep(a, 10){
		
		ll cur = S[i] - '0';
		
		if(a == 0){
			
			if(cur != 0){
				for(ll k = 3; k >= 0; k--){
					dp[i + 1][0][k] += dp[i][0][k] + dp[i][1][k];
				}
			}
			
			else{
				for(ll k = 3; k >= 0; k--){
					dp[i + 1][0][k] += dp[i][0][k];
					dp[i + 1][1][k] += dp[i][1][k];
				}
			}
			
		}
		
		else{
			
			if(cur > a){
				for(ll k = 2; k >= 0; k--){
					dp[i + 1][0][k + 1] += dp[i][0][k] + dp[i][1][k];
				}
			}
			
			else if(cur == a){
				for(ll k = 2; k >= 0; k--){
					dp[i + 1][0][k + 1] += dp[i][0][k];
					dp[i + 1][1][k + 1] += dp[i][1][k];
				}
			}
			
			else{
				for(ll k = 2; k >= 0; k--){
					dp[i + 1][0][k + 1] += dp[i][0][k];
				}
			}
			
		}
		
	}
	
	ll length = S.size();
	ll ans = dp[length][0][K] + dp[length][1][K];
	print(ans);				
		
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	Main();
	return 0;
	
}



