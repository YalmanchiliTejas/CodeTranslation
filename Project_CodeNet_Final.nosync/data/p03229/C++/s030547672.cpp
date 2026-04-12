#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
using namespace std;
const int mod = 1000000007;
#define ll long long

ll A[100010];
int main()
{
	int N; cin >> N;
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);
	for (int i = 0; i < N / 2; i++) {
		ans += (A[N - 1 - i] - A[i]) * 2;
	}
	if (N % 2 == 0) {
		ans += A[N / 2 - 1] - A[N / 2];
	}
	else {
		ans += max(A[N / 2 - 1] - A[N / 2], A[N / 2] - A[N / 2 + 1]);
	}
	cout << ans << endl;
}