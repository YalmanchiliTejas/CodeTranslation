#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif

const int inf=1e9;
const int64_t inf64=1e18;
const double eps=1e-9;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

using i64=int64_t;

vector<i64> fact;
void init_fact(i64 n,i64 m){
	fact.resize(n+1);
	fact[0]=fact[1]=1;
	for(i64 i=2; i<=n; ++i) fact[i]=(i*fact[i-1])%m;
}

i64 extgcd(i64 a,i64 b,i64 &x,i64 &y){
	i64 d=a;
	if(b!=0){
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	} else {
		x=1; y=0;
	}
	return d;
}

i64 mod_inverse(i64 a,i64 m){
	i64 x,y;
	if(extgcd(a,m,x,y)==1) return (x+m)%m;
	return 0;
}

i64 rep_pow(i64 x,int64_t y,i64 mod){
	i64 res(1);
	while(y>0){
		if(y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}

vector<vector<i64>> comb;
void init_mod_comb(int n,int k,i64 mod){
	comb.resize(n+1);
	for(int i=0; i<=n; ++i){
		comb[i].resize(min(i+1,k+1));
		comb[i][0]=1;
		if(i<=k) comb[i][i]=1;
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=min(i-1,k); ++j){
			comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%mod;
		}
	}
}

void solve(){
	i64 mod=1000000007;
	init_mod_comb(1024,1024,mod);
	init_fact(1024*1024,mod);
	/*
	vector<i64> inv(1001*1001);
	rep(i,1,1001*1001) inv[i]=mod_inverse(i,mod);
	*/
	//i64 inv_table[1000000];
	//rep(i,1,1000000) inv_table[i]=mod_inverse(i,mod);
	auto inv=[&](i64 x){
		//if(x<1000000) return inv_table[x];
		return mod_inverse(x,mod);
	};

    i64 N,A,B,C,D;
    cin >> N >> A >> B >> C >> D;
    static i64 dp[1024][1024];
    fill_n((i64*)dp,1024*1024,0);
    dp[A][0]=1;
    rep(i,C,D+1){
        if(A*i>N) break;
        dp[A][A*i]=comb[N][A*i]*fact[A*i]%mod*inv(fact[i]*rep_pow(fact[A],i,mod)%mod)%mod;
    }

	rep(i,A,B){
		rep(j,0,N+1){
			dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
			rep(k,C,D+1){
				if(j+(i+1)*k>N) break;
				dp[i+1][j+(i+1)*k]=(dp[i+1][j+(i+1)*k]+dp[i][j]*comb[N-j][(i+1)*k]%mod*fact[(i+1)*k]%mod*inv(fact[k]*rep_pow(fact[i+1],k,mod)%mod)%mod)%mod;
			}
		}
	}

	cout << dp[B][N] << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}
