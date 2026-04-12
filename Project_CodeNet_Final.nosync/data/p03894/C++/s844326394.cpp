#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)



int N, Q;
bool dp[101010];
bool dp2[101010];
//-----------------------------------------------------------------
int main() {
	cin >> N >> Q;

	dp[1] = true;
	dp2[2] = true;

	int bb = 1;
	rep(i, 0, Q) {
		int a, b;
		scanf("%d %d", &a, &b);

		swap(dp[a], dp[b]);
		swap(dp2[a], dp2[b]);
		if (dp[a]) bb = a;
		if (dp[b]) bb = b;
		dp2[bb - 1] = dp2[bb - 1] | dp[bb];
		dp2[bb + 1] = dp2[bb + 1] | dp[bb];
	}

	int ans = 0;
	rep(i, 1, N + 1) if (dp[i] || dp2[i]) ans++;
	cout << ans << endl;
}