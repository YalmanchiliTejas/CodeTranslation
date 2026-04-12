#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
	
	int n;
	cin >> n;
	vector<int> h(n);
	rep(i, n) cin >> h[i];
	int ans = 0;
	int max = 0;
	rep(i, n){
		if(max <= h[i]){
			ans++;
			max = h[i];
		}
	}
	cout << ans << endl;
	return 0;
}