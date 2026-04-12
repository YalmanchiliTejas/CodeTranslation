#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=2e5;
const int inf=1e9;
long calc(long x,long y){
	long z = ((x - 1) * x * (x + 1) / 6) % mod;
	return (z * y * y) % mod;
}
long modfact(long n,long p){//n! mod p
    if(n >= p) return 0;
    long res = 1;
    rep(i,1,n+1) (res *= i) %= p;
    return res;
}
long modperm(long n,long r,long p){//nPr mod p
    if( n-r >= p || r%p > n%p) return 0;
    long res = 1;
    rep(i,n-r+1,n+1) (res*=i) %= p;
    return res;
}
long modcomb(long n,long r,long p){//nCr mod p
    long x = modfact(max(n-r,r),p);
    long y = modperm(n,max(n-r,r),p);
	int i = 0;
	while( (p-2) >= (1<<i) ){
		if( (p-2) & (1<<i) ) (y*=x)%=p;
		i++; x = x * x % p;
	}
	return y;
}
long modpow(long x,int n,long p){
	int i = 0;long res = 1;
	while(n >= (1<<i)){
		if(n & (1<<i)) (res *= x) %= p;
		i++;
		x = (x * x) % p;
	}return res;
}
int main(){
	long N,M,K;cin>>N>>M>>K;
	long res = (calc(N, M) + calc(M, N)) % mod;
	(res *= modperm(N * M - 2, K - 2, mod)) %= mod;
	(res *= ((K - 1) * K) % mod) %= mod;
    (res *= modpow(modfact(K, mod), mod-2, mod)) %= mod;
	cout<<res<<endl;
}