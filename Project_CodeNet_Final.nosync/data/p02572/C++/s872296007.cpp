#include <cstdio> 
#include <iostream> 
using namespace std;
typedef long long ll;            //>10^18
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
ll n;
ll a[MAXN];
int main(int argc, char *argv[]){
	scanf("%lld", &n);
	ll cnt = 0;
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		cnt += a[i];
	}
	ll ans = 0, cot, save;
	for(int i = 1; i <= n; i++){
		save = cnt - a[i];
		cnt -= a[i];
		cot = ((a[i] % MOD) * (save % MOD)) % MOD;
		ans = ((ans % MOD) + (cot % MOD)) % MOD;
	} 
	cout << ans;
	return 0;
}