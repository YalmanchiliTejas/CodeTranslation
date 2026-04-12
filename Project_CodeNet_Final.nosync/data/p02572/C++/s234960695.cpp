#include <cstdio> 
#include <iostream> 
using namespace std;
typedef long long ll;            //>10^18
typedef long double ld;          //3.3621e-4932 ~ 1.18937e4932
typedef unsigned long long ull;  //>10^20
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;  
int n;
ll a[MAXN];
ll s[MAXN] = {0};
int main(int argc, char *argv[]){
	scanf("%ull", &n);
	ll cnt = 0;
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		cnt += a[i];
	}
	for(int i = 1; i <= n; i++){
		s[i] = cnt - a[i];
		cnt -= a[i];
	} 
	int ans = 0, cot;
	for(int i = 1; i <= n; i++){
		cot = ((a[i] % MOD) * (s[i] % MOD)) % MOD;
		ans = ((ans % MOD) + (cot % MOD)) % MOD;
	} 
	cout << ans;
	return 0;
}