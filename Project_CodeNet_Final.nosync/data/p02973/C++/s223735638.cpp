#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int A[N], dp1[N], dp2[N], len1 = 1, len2 = 1;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)scanf("%d", &A[i]);
	dp1[1] = dp2[1] = A[1];
	for (int i = 2; i <= n; i++) {
		if (dp1[len1] >= A[i])dp1[++len1] = A[i];
		else dp1[upper_bound(dp1 + 1, dp1 + 1 + len1, A[i], greater<int>()) - dp1] = A[i];
		if (dp2[len2] < A[i])dp2[++len2] = A[i];
		else dp2[lower_bound(dp2 + 1, dp2 + 1 + len2, A[i]) - dp2] = A[i];
	}
	printf("%d", len1);
}