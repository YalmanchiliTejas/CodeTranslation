#include<bits/stdc++.h>
#define LL long long
#define REP(i,n) for(int i=0;i<(n);++i)
#define PER(i,n) for(int i=n-1;i>=0;--i)
#define REPA(i,n) for(int i=1;i<(n);++i)
#define foreach(i, n) for(auto &i:(n))
#define PII pair<int,int>
#define PLI pair<long long, int>
#define PLL pair<long long, long long>
#define MOD ((LL)1e9+7) 
#define INF ((int)1e9+7)
#define INFLL ((LL)1e18)
#define ALL(x) (x).begin(),(x).end()
#define BIT(x) (1LL << (x))
using namespace std;

LL modpow(LL x, LL b){
	LL res = 1;
	while(b){
		if(b&1)res = res * x % MOD;
		x = x * x % MOD;
		b>>=1;
	}
	return res;
}

LL modinv(LL x){
	return modpow(x, MOD-2);
}

LL pati(LL x){
	return BIT(x+1)-1;
}

LL sum(LL x){
	return BIT(2+x)-3;
}

LL func(LL N, LL X){
	if(X<=0)return 0;
	LL res = 0;
	REP(i, 2){
		if(X<=0)break;
		--X;
		if(i==1)++res;
		if(X<sum(N-1)){
			res += func(N-1, X);
			break;	
		}
		res += pati(N-1);
		X -= sum(N-1);
	}
	return res;
}

int main(){
	LL N, X;
	cin >> N >> X;
	cout << func(N, X) << endl;
	return 0;
}
