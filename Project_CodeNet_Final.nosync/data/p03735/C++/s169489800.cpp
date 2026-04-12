#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int INF = 1e18 + 13, maxN = 2e5 + 13;;
int n, ans = INF, mxy, mxx, mnx = INF, mny = INF, x[maxN], y[maxN];
int arr[maxN];

bool cmp (int i, int j) {
    if (x[i] != x[j])
	return x[i] < x[j];
    if (y[i] != y[j])
	return y[i] < y[j];
    return i < j;
}

int32_t main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
	cin >> x[i] >> y[i];
	if (y[i] < x[i])
	    swap(x[i], y[i]);
	mnx = min(mnx, x[i]);
	mxx = max(mxx, x[i]);
	mny = min(mny, y[i]);
	mxy = max(mxy, y[i]);
    }
    iota(arr, arr + n, 0);
    sort(arr, arr + n, cmp);
    int mn = INF, mx = mxx;
    for (int i = 1; i < n; i++) {
	mx = max(mx, y[arr[i - 1]]), mn = min(mn, y[arr[i - 1]]);
	ans = min(ans, (mxy - mnx) * (mx - min(x[arr[i]], mn)));
    }
    cout << min(ans, (mxx - mnx) * (mxy - mny)) << endl;
    return 0;
}
