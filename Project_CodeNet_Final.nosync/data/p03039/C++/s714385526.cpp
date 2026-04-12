#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

struct modint{
	int v = 0;
	int operator=(const int& rhs){
		v = rhs;
		return v;
	}
	bool operator==(const modint& rhs){
		return (v == rhs.v);
	}
	modint operator+(const modint &rhs){
		modint ret;
		ret.v = v + rhs.v;
		ret.v = (ret.v<MOD)?ret.v:(ret.v-MOD);
		return ret;
	}
	void operator+=(const modint &rhs){
		v += rhs.v;
		v = (v<MOD)?v:(v-MOD);
	}
	modint operator-(const modint &rhs){
		modint ret;
		ret.v = v - rhs.v;
		ret.v = (ret.v<0)?(ret.v+MOD):ret.v;
		ret.v = (ret.v<MOD)?ret.v:(ret.v-MOD);
		return ret;
	}
	void operator-=(const int &rhs){
		v -= rhs;
		v = (v<0)?v+MOD:v;
		v = (v<MOD)?v:(v-MOD);
	}
	void operator-=(const modint &rhs){
		v -= rhs.v;
		v = (v<0)?v+MOD:v;
		v = (v<MOD)?v:(v-MOD);
	}
	modint operator*(const modint &rhs){
		ll tmp = 1ll;
		modint ret;
		tmp *= v;
		tmp *= rhs.v;
		tmp %= MOD;
		ret.v = tmp;
		return ret;
	}
	void operator*=(const modint &rhs){
		ll tmp = 1ll;
		tmp *= v;
		tmp *= rhs.v;
		tmp %= MOD;
		v = tmp;
	}
	modint operator/(const modint &rhs){
		modint ret;
		ll t=1ll,a,p = MOD-2;
		a = rhs.v;
		while(p){
			if(p%2){
				t *= a;
				t %= MOD;
			}
			a *= a;
			a %= MOD;
			p /= 2;
		}
		t *= v;
		t %= MOD;
		ret.v = t;
		return ret;
	}
	void operator/=(const modint &rhs){
		ll t=1ll,a,p = MOD-2;
		a = rhs.v;
		while(p){
			if(p%2){
				t *= a;
				t %= MOD;
			}
			a *= a;
			a %= MOD;
			p /= 2;
		}
		t *= v;
		t %= MOD;
		v = t;
	}
	bool operator<(const modint &rhs){
		return (v<rhs.v);
	}
	bool operator<=(const modint &rhs){
		return (v<=rhs.v);
	}
	void operator ++() {
		v += 1;
		v = (v<MOD)?v:(v-MOD);
	}
};

ostream& operator <<(ostream& o, const modint &rhs){
	o << rhs.v;
	return o;
}

istream& operator >>(istream& o, modint& rhs){
	o >> rhs.v;
	return o;
}

int main(void){
	modint i,n,m,k,ans,t;
	cin >> n >> m >> k;
	t = n*m;
	for(i=1; i<n; ++i){
		ans += (i)*(n-i)*m*m;
	}
	for(i=1; i<m; ++i){
		ans += (i)*(m-i)*n*n;
	}
	k -= 2; t -= 1;
	for(i=1; i<=k; ++i){
		ans *= (t-i);
		ans /= i;
	}
	cout << ans << endl;
	return 0;
}
