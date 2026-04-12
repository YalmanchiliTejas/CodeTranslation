#include <iostream>
#include <cmath>

#define ll long long
#define MAX 3010

using namespace std;
ll mod,dp[3010][3010],f[3010]={0},cnk[3010][3010];
ll pw(ll a, ll b) {
	ll ans = 1; 
	while (b) {
		while (b%2==0){
			b /= 2;
			a = (a * a) % mod;
		}
		ans = (ans * a) % mod;
		--b;
	}
	return ans;
}

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

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll i,j,n;
	cin >> n >> mod;
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			dp[i][j] = 0;
		}
	}

	dp[0][0] = 1;
	for(i=1;i<=n;i++){
		for(j=0;j<=i;j++){
			if(j==0){
				dp[i][j] = 1;
			}else{
				dp[i][j] = (dp[i-1][j-1] + (j+1)*dp[i-1][j]%mod)%mod;
			}
		}
	}

	for(i=0;i<=n;i++){
		mod--;
		ll x = pw(2,(n-i));
		mod++;
		ll y = pw(2,x);
		ll z = pw(2,(n-i));
		for(j=0;j<=i;j++){
			f[i] += y*pw(z,j)%mod*dp[i][j]%mod;
			f[i] = f[i]%mod;
		}
	}

	ll ans = 0,u = -1;
	inverse();
	factinv();
	for(i=0;i<=n;i++){
		cnk[n][i] = comb(n,i);
	}
	
	for(i=0;i<=n;i++){
		ll k = cnk[n][i]*f[i]%mod;
		u *= -1;
		ans += u*k;
		ans = (ans+mod)%mod;
	}
	
	cout << ans << endl;
}
