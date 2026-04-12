#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<utility>
#include<map>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;

#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define stop char nyaa; cin>>nyaa;


void solve() {
	int n;
	cin >> n;
	vector<int> isprime(33333, 1);
	isprime[0] = isprime[1] = 0;
	vector<int> prime;
	rep(i, 33333) {
		if (!isprime[i])continue;
		prime.push_back(i);
		for (int j = 2 * i; j < 33333; j += i) {
			isprime[j] = 0;
		}
	}
	map<int, long long> mp;
	rep(i, n) {
		int x;
		cin >> x;
		int y = x;
		for (auto p : prime) {
			if (y%p)continue;
			mp[p] += x;
			while (y%p == 0)y /= p;
			
		}
		if (y > 1)mp[y] += x;
	}
	long long ans = 0;
	for (auto e : mp) {
		ans = max(ans, e.second);
	}
	cout << ans << endl;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	//stop
	return 0;
}
