#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = n - 1; i >= 0; --i)
#define pb push_back

typedef long long ll;

int main() {
	int n; cin >> n;
	int h[n+1];
	REP(i, n){
		cin >> h[i];
	}
	
	int ans = 1;
	int d = h[0];

	FOR(i, 1, n){
		d = max(d, h[i-1]);
		if (d <= h[i]){
			++ans;
		}
	}

	cout << ans << endl;

	return 0;
}