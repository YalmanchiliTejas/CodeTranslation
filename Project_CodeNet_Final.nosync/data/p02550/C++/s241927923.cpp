#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll b[100005];
ll rui[100005];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, x, m;
	cin >> n >> x >> m;
	ll idx = 0;
	ll cur = x, sum = 0;
	memset(b, 0, sizeof(b));
	while(b[cur] == 0 && idx < n){
		++idx;
		sum += cur;
		rui[idx] = sum;
		b[cur] = idx;
		cur = (cur * cur) % m;
		if(cur == 0){
			cout << sum << endl;
			return 0;
		}
	}
	if(idx == n){
		cout << sum << endl;
		return 0;
	}
	ll idx2 = b[cur] - 1;
	n -= idx2;
	ll ans = (sum - rui[idx2]) * (n / (idx - idx2));
	//cout << ans << endl;
	n %= (idx - idx2);
	ans += rui[idx2 + n];
	cout << ans << endl;
	return 0;
}
