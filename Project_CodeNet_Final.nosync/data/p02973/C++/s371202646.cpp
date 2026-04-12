#include<iostream>
#include<algorithm>

using namespace std;

int N;
int A[100000];
int dp[100000];
const int INF = 1145141919;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> A[i], dp[i] = INF;
	reverse(A, A + N);
	for (int i = 0; i < N; i++) {
		*upper_bound(dp, dp + N, A[i]) = A[i];
	}

	cout << (lower_bound(dp, dp + N, INF) - dp) << endl;
	return 0;
}