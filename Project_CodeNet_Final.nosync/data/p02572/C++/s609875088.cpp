//Har Har Mahadev
using namespace std;
#include <bits/stdc++.h>
#define booga cout << "booga" << endl
#define ll long long int
#define pb push_back
#define mp make_pair
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " -> " << a << endl;
	err(++it, args...);
}
const ll mod = 1e9 + 7;
void testcase(){
	ll n,a[200005];
	ll ans = 0,sum = 0;
	cin >> n;
	for(int i{0};i < n;i++)cin >> a[i];
	for(int i{0};i < n;i++){
		sum += a[i];
		sum %= mod;
	}
	for(int i{0};i < n;i++){
		sum -= a[i];
		sum = (sum + 5*mod)%mod;
		ans += a[i]*sum;
		ans %= mod;
	}
	cout << ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while(t--){
		testcase();
	}
	return 0;
}
