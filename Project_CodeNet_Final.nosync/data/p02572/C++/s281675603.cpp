#include <bits/stdc++.h>
#define newl "\n"
using namespace std;
using lli = long long int;
using vvint = vector <vector <int>>;
const int mod = 1e9 + 7;

const int N = 2e5 + 1;

void solve(){
	int n;
	cin >> n;
	vector <int> a(n);
	vector <lli> summ(n + 1,0);
	for(int i = 0;i < n;++i){
		cin >> a[i];
		summ[i + 1] = summ[i] + a[i];
	}
	lli ans = 0;
	for(int i = 0;i < n;++i){
		ans = ans + ((lli)a[i] * ((summ[n] - summ[i + 1]) % mod)) % mod;
		ans = ans % mod;
	}
	cout << (ans + mod) % mod << newl;

	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(10);
	#ifdef EXECUTE_LOCALLY
		   freopen("in.txt","r",stdin);
	#endif
	int t = 1;
	//cin >> t;
	while(t--) solve();
	#ifdef EXECUTE_LOCALLY
    	cout << setprecision(3) << "program time: " << (double)clock() / CLOCKS_PER_SEC << newl;
	#endif
	return 0;
}
