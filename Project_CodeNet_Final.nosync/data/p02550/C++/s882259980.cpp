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

const int mod = 998244353;
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

	ll N, X, M;
	cin >> N >> X >> M;
	
	vl acc(1);
	map<ll, ll> mp;
	ll ans = 0;

	rep(i, N){

		if(mp[X]){
			if(X == 0){
				print(ans);
				return;
			}
			ll bef = mp[X];
			ll loop = i - bef;
			ll cnt = (N - i) / loop;
			ll accs = acc[i] - acc[i - loop];
			ll mod = (N - i) % loop;
			ans = (ans + accs * cnt + acc[bef + mod] - acc[bef]);
			/*
			printv(acc);
			print(loop);
			print(cnt);
			print(bef);
			print(accs);
			print(mod);
			*/
			break;
		}

		mp[X] = i;
		ans += X;
		acc.push_back(acc[i] + X);
		X = (X * X) % M;
	}

	print(ans);	

}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	Main();
	return 0;
	
}



