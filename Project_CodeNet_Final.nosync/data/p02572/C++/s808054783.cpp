#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define FOR(i, n) for(int i = 1; i<=n; i++)
#define F0R(i, n) for(int i = 0; i<n; i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
const LL MOD = 1e9+7;
LL a[200005], ans = 0, n, sf[200005];

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;
	FOR(i, n) cin >> a[i];
	FOR(i, n) a[i] %= MOD;
	for(int i = n; i>=1; i--){
		sf[i] = a[i];
		sf[i] += sf[i+1];
		sf[i] %= MOD;
		//cout << i << " " << sf[i] << endl;
	}
	FOR(i, n-1){
		ans += (a[i] * (sf[i+1]))%MOD;
		ans %= MOD;
	}

	cout << ans << endl;

	cout.flush();
	return 0;
}