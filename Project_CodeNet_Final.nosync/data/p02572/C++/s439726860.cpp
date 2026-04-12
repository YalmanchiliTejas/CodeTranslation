#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200010;
const long long P = 1000000007;
int N;
long long A[MAX_N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	
	long long sum = 0, sos = 0;
	for (int i = 0; i < N; i++) {
		sum = (sum + A[i]) % P;
		sos = (sos + ((A[i] * A[i]) % P)) % P;
	}
	
	long long ans = (((P + 1LL) / 2LL) * ((((sum * sum) % P) - sos + P) % P)) % P;
	cout << ans << "\n";
	
	return 0;
}
