#pragma GCC optimize("-Ofast")

#include <bits/stdc++.h>

#define ll long long
#define INF ((int)1e9+1)

using namespace std;

signed main(){
    /* 入力の受け取り(Aは逆順) */
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 1;i <= n;++i)
        cin >> a[n - i];
    /* 逆順AのLISを考える */
    int dp[n];
	fill(dp, dp + n, INF);
	for (int i = 0; i < n; ++i) {
		*lower_bound(dp, dp + n, a[i] + 1) = a[i];
	}
    cout << lower_bound(dp, dp + n, INF) - dp << endl;
    /* メモリの開放、プログラムの終了 */
    delete[] a;
    return 0;
}