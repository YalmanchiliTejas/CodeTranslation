#include <bits/stdc++.h>

using namespace std;

#define LL long long 
#define ULL unsigned LL
#define LD long double 

const LL MOD = 1e9 + 7;

long long inv(long long a, long long b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	LL a[n];
	LL ans = 0;
	LL suma = 0;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		suma+=a[i];
	}
	for(int i=0; i<n; i++) {
		LL x = suma - a[i];
		x %= MOD;
		LL y = a[i] * x;
		y %= MOD;
		ans += y;
		ans %= MOD;
	}
	LL dziel = inv(2, MOD);
	ans *= dziel;
	ans %= MOD;
	cout<<ans;
}
