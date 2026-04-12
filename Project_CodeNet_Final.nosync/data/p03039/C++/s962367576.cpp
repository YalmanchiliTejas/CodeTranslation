#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007

lli func(lli x1,lli x2,lli y1,lli y2){
	return abs(x1-x2)+abs(y1-y2);
}

const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

signed main(){

	COMinit();

	lli n,m;
	cin>>n>>m;
	lli k;
	cin>>k;

	lli ans=0;

	/*xの距離がiの数をansに足し合わせる*/
	REP(i,0,m)ans = (ans+n*n%MOD*(m-i)%MOD*i%MOD)%MOD;
	REP(i,0,n)ans = (ans+m*m%MOD*(n-i)%MOD*i%MOD)%MOD;

	cout<<ans*COM(n*m-2,k-2)%MOD<<endl;
	

	return 0;
}