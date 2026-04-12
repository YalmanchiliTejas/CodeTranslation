#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	ll n;cin>>n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	
	vector<ll> a_sum(n + 1,0);
	for(int i = 1; i <= n; i++) {
		a_sum[i] = a[n - i] + a_sum[i - 1];
		a_sum[i] %= mod;
	}
	ll ans = 0;
	for(int i = 0; i < n - 1; i++) {
		ans += a[i] * (a_sum[n - i - 1]) % mod;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}