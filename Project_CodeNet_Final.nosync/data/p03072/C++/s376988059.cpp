#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> h(n);
	rep(i, n) cin >> h[i];

	int mx = 0;
	int ans = 0;
	rep(i, n){
		if(h[i] >= mx){
			mx = h[i];
			ans++;
		}
	}

	cout << ans << endl;
}
