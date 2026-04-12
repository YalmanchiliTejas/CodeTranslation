#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define rep(i,n) for(int i = 0; i < (n); i++)
#define INF ((long long)1e18)
#define MOD ((int)1e9+7)
#define endl "\n"

#define yn(f) ((f)?"Yes":"No")
#define YN(f) ((f)?"YES":"NO")

#define MAX 210000

#define MAX_VAL MAX

long long fac[MAX_VAL], mmi[MAX_VAL];

void factorial_mod(){
	 fac[0]=fac[1]=1;
	for(long long i = 2; i < MAX_VAL; fac[i]%=MOD,i++)
		fac[i] = fac[i-1]*(i%MOD);
}

long long power_mod(long long x, long long n){
	long long ans = 1;
	for(;n;n>>=1,x*=x,ans%=MOD,x%=MOD)
		if(n&1)ans*=x;
	return ans%MOD;
}

void exgcd(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return ;
	}
	exgcd(b,a%b,y,x);
	y -= a/b * x;
}

void modular_multiplicatibe_inverse(){
	int x, y;  
	exgcd(fac[MAX_VAL-1],MOD,x,y);
	mmi[MAX_VAL-1] = x;
	for(long long i = MAX_VAL-2; i >= 0; mmi[i]%=MOD,i--)
		mmi[i] = mmi[i+1]*((i+1)%MOD);
}

long long combination(long long n, long long r){
	return fac[n]*(mmi[r]*mmi[n-r]%MOD)%MOD;
}


signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int N, M, K;
	int sum = 0;
	int com = 0;
	
	factorial_mod();
	modular_multiplicatibe_inverse();
	
	cin>>N>>M>>K;
	
	com = combination(N*M-2,K-2);
	
	// cout<<com<<endl;
	
	for(int i = 1; i <= N; i++){
		sum += com*(N-i)%MOD*M*M%MOD*i;
		sum %= MOD;
	}
	for(int i = 1; i <= M; i++){
		sum += com*(M-i)%MOD*N*N%MOD*i;
		sum %= MOD;
	}
	cout<<sum<<endl;
	
	return 0;
}