#include <bits/stdc++.h>
using namespace std;

#define MOD (1000000000+7)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) x.begin(), x.end()
#define print(vec,l,r) for(int i = l; i <= r; i++) cout << vec[i] <<" "; cout << endl;
#define forf(i,a,b) for(int i = (a); i < (b); i++)
#define forr(i,a,b) for(int i = (a); i > (b); i--)
#define input(vec,N) for(int i = 0; i < (N); i++) cin >> vec[i];
#define debug(x) cout << #x << "= " << x<< endl;
// template starts
typedef long long int ll;

// template ends here

void solve(){
	// code starts from here
	int N;
	cin >> N;
	vector<ll> vec(N);
	ll sum = 0;
	for(int i = 0; i < N; i++){
		cin >> vec[i];
		sum += vec[i];
	}
	sum %= MOD;
	ll ans = 0;
	
	for(int i = 0; i < N; i++){
		ans += (vec[i]*(sum-vec[i]));
		ans %= MOD;
		ans += MOD;
		ans %= MOD;
		
		sum -= vec[i];
		sum %= MOD;
		sum += MOD;
		sum %= MOD;
	}
	cout << ans << endl;
}

int main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int T;
	T = 1;
	while(T--){
		solve();
	}

	return 0;
}
