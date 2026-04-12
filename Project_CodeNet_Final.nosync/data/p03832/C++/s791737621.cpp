#include <iostream>

using namespace std;

#define MAX 200010
long long mod = 1000000007;
long long inv[MAX],fact[MAX],fi[MAX];

void inverse(){
	int i;
	inv[1] = 1;
	for(i=2;i<MAX;i++){
		inv[i] = mod - (mod/i)*inv[mod%i]%mod;
	}
}

void factinv(){
	int i;
	fact[0] = fi[0] = 1;
	for(i=1;i<MAX;i++){
		fact[i] = fact[i-1]*i%mod;
		fi[i] = (fi[i-1]*inv[i])%mod;
	}
}

long long comb(int n,int k){
	if(n<0 || k<0 || n<k){
		return 0;
	}else{
		return fact[n]%mod*fi[k]%mod*fi[n-k]%mod;
	}
}

long long pow(long long a,long long b){
	if(b==0){
		return 1;
	}else{
		if(b%2==0){
			return pow(a,b/2)*pow(a,b/2)%mod;
		}else{
			return pow(a,b/2)*pow(a,b/2)%mod*a%mod;
		}
	}
}
long long i,j,k,n,a,b,c,d,dp[1010][1010];
int main(){
	cin >> n >> a >> b >> c >> d ;
	for(i=1;i<=n;i++){
		dp[a-1][i] = 0;
	}
	dp[a-1][0] = 1;
	inverse(); factinv();
	for(i=a;i<=b;i++){
		for(j=0;j<=n;j++){
			dp[i][j] = dp[i-1][j];
			for(k=c;k*i<=j && k<=d ;k++){
				dp[i][j] += fact[n+k*i-j]*fi[n-j]%mod*pow(fi[i],k)%mod*fi[k]%mod*dp[i-1][j-k*i]%mod;
				dp[i][j] = dp[i][j]%mod;
			}
		}
	}
	cout << dp[b][n] << endl;
}