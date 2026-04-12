#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

void solve();

signed main () {
    cout.precision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int t = 1; 
    // cin >> t;	
    int tt = t;
    while (t--) { 
        solve();
    }
    return 0;
}
int n;
void solve() {
	cin >> n;
	cout << (800 * n - 200 * (n / 15));	
}     	