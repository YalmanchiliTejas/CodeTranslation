#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<cassert>

using namespace std;

#define sz(x) (int)(x.size())
#define fi(a, b) for(int i=a;i<b;++i)
#define fj(a, b) for(int j=a;j<b;++j)
#define fk(a, b) for(int k=a;k<b;++k)
#define pb push_back
#define mp make_pair
typedef long long ll;
/////////////////////////

int const N = 1e3 + 41;
int const MOD = 1e9 + 7;

int n, a, b, c, d, f[N], invF[N], dp[N][N], invFd[N][N];

void add(int &a, int b){
	a += b;
	if(a >= MOD){
		a -= MOD;
	}
}

int mul(int a, int b){
	return a * 1LL * b % MOD;
}

int bp(int x, int d){
	if(!d){
		return 1;
	}
	if(d&1){
		return mul(x, bp(x, d-1));
	}
	int r = bp(x, d/2);
	return mul(r, r);
}

int getC(int k, int n){
	if(k > n){
		return n;
	}
	return mul(f[n], mul(invF[k], invF[n-k]));
}

void precalc(){
	invF[0] = f[0] = 1;
	fi(1, N){
		f[i] = mul(i, f[i-1]);
		invF[i] = bp(f[i], MOD-2);
		invFd[i][0] = 1;
		fj(1, N){
			invFd[i][j] = mul(invFd[i][j-1], invF[i]);
		}
	}
}

int fun(int k, int i, int j){
	int ret = f[i*k];
	ret = mul(ret, getC(i * k, n - j));
	ret = mul(ret, invFd[i][k]);
	ret = mul(ret, invF[k]);
	return ret; 
}

void solve(){
	precalc();
	dp[a-1][0] = 1;
	for(int i=a;i<=b;++i){
		for(int j=0;j<=n;++j){
			add(dp[i][j], dp[i-1][j]);
			for(int k=c;k<=d && k * i + j <= n;++k){
				add(dp[i][j + k * i], mul(dp[i-1][j], fun(k, i, j)));
			}
		}
	}
	printf("%d\n",dp[b][n]);
}

void read(){
	scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);
}

void prepare(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}

int main(){
	prepare();
	read();
	solve();


	return 0;
}
