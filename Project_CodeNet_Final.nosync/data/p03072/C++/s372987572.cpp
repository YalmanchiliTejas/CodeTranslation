#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9+7;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> h(n);
	rep(i, n) cin >> h.at(i);
	int ans = 0;
	int now = h.at(0);
	rep(i, n){
		if(h.at(i) >= now){
			ans++;
			now = h.at(i);
		}
	}
	cout << ans << endl;
}
