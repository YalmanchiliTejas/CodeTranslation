#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

const int mod = 1000000007;

class mint {
    long long x;
public:
    mint(long long x=0) : x((x%mod+mod)%mod) {}
    mint operator-() const { 
      return mint(-x);
    }
    mint& operator+=(const mint& a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint& a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const  mint& a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint& a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint& a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint& a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint& a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint& a) const {
        mint res(*this);
        return res/=a;
    }

    friend ostream& operator<<(ostream& os, const mint& m){
        os << m.x;
        return os;
    }
};

// ll mod = 1e9+7;

ll solve1(vector<ll> A, ll N){
	ll sum=0;
	for(int i=0; i<N-1; i++){
		for(int j=i+1; j<N; j++){
			sum += (A[i]*A[j])%mod;
			sum %= mod;
		}
	}
	return sum;
}



int main(){
	ios::sync_with_stdio(false);
	
	ll N; cin>>N;
	vector<ll> A(N);
	rep(i,N) cin>>A[i];

	mint zyowa=0,  sum=0;
	for(int i=0; i<N; i++){
		zyowa += (A[i]*A[i])%mod;
		sum += A[i];
		//zyowa %= mod;
		//sum %= mod;
		// cerr << "zyowa: " << zyowa << endl;
		// cerr << "sum: " << sum << endl;
	}

	mint ans = (sum*sum);
	ans = (ans - zyowa);
	ans /= 2;
	cout << ans << endl;

	// cout << solve1(A,N) << endl;
}
