#include <iostream>
#include <cmath>

#define ll long long
#define MAX 3010
#define v 9000100
using namespace std;
ll m,mod,dp[3010][3010],f[3010]={0},bek1[v] = {0},bek[v]={0},cnk[3010][3010];
ll beki(ll x, ll a){
	if(a<v && bek[a]!=0){
		return bek[a];
	}
	if(a==0){
		bek[a] = 1;
		return 1;
	}else if(a%2==0){
		if(a<v){
			bek[a] = beki(x,a/2)*beki(x,a/2)%mod;
		}
		return beki(x,a/2)*beki(x,a/2)%mod;
	}else{
		if(a<v){
			bek[a] = beki(x,a/2)*beki(x,a/2)%mod*x%mod;
		}
		return beki(x,a/2)*beki(x,a/2)%mod*x%mod;
	}
}

ll beki1(ll x, ll a){
	if(bek1[a]!=0){
		return bek1[a];
	}
	if(a==0){
		bek1[a] = 1;
	}else if(a%2==0){
		bek1[a] = beki1(x,a/2)*beki1(x,a/2)%m;
	}else{
		bek1[a] = beki1(x,a/2)*beki1(x,a/2)%m*x%m;
	}
	return bek1[a];
}

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

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll i,j,n;
	cin >> n >> mod;
	m = mod - 1;
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
		mod -= 1;
		ll x = pw(2,(n-i));
		mod += 1;
		ll y = pw(2,x);
		ll z = pw(2,(n-i));
		for(j=0;j<=i;j++){
			f[i] += y*pw(z,j)%mod*dp[i][j]%mod;
			f[i] = f[i]%mod;
		}
	}

	for (int i = 0; i <= n; ++i){
		for (int j = 0; j <= n; ++j) {
			if (i == j || j == 0)
				cnk[i][j] = 1;
			else if (j > i)
				cnk[i][j] = 0;
			else
				cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % mod;
		}
	}
	
	ll ans = 0;
	for(i=0;i<=n;i++){
		ll k = cnk[n][i]*f[i]%mod;
		ans += pow(-1,i)*k;
		ans = (ans+mod)%mod;
	}
	
	cout << ans << endl;
}
