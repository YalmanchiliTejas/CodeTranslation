#include<bits/stdc++.h>
using namespace std;
#define Maxn 200005
#define MOD 1000000007
int n,a[Maxn];
long long ans,s[Maxn];
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	s[n] = a[n] % MOD;
	for(int i = n - 1;i >= 1;i--)
		s[i] = (a[i] + s[i + 1]) % MOD;
	for(int i = 1;i < n;i++)
		ans = (ans + a[i] * s[i + 1] % MOD) % MOD;
	cout << ans << endl;
	return 0; 
}
