#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const ll INF=1e18;
const ll mod = 1e9 + 7;


int main() {
	int	n;
	ll sum = 0, ans = 0;
	cin >> n;
	vector<ll> a(n);
	rep(i,n){
		cin >> a[i];
	}
	rep(i,n - 1){
		sum += a[i];
		sum %= mod;
		ans += sum * a[i + 1] % mod;
		ans %= mod;
	}
	cout << ans <<endl;
}