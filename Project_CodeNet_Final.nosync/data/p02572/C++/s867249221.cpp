#include<bits/stdc++.h>
using namespace std;

#define ll long long
// #define endl '\n'

// void max_self(int &a, int b){a = max(a, b);}
// void min_self(int &a, int b){a = min(a, b);}

const int MOD = 1e9 + 7;

void solve(){
	int n; cin>>n;
	vector< ll > v(n), pref;
	for(ll &i : v) cin>>i;
	pref = v;
	for(int i = 1; i<n; i++){
		pref[i] += pref[i - 1];
		if(pref[i] >= MOD){
			pref[i] -= MOD;
		}
	}
	ll ans = 0;
	for(int j = 1; j<n; j++){
		ans += v[j] * pref[j - 1];
		ans = ans % MOD;
	}
	cout<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;// cin>>t;
	for(int i = 1; i<=t; i++){
		solve();
	}
	return 0;
}
