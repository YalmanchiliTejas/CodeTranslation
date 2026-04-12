#include "bits/stdc++.h"
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2")

using namespace std;

using ll = long long;
#define all(x) begin(x), end(x)

int main()
{
    ios_base::sync_with_stdio(0);
   	int N;
	cin >> N;
	vector<int> A(N);
	vector<long long> B(N + 1, 0); 
	int mod = 1000000007;
 
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		B[i + 1] = B[i] + A[i];
	}
 
	long ans = 0;
 
	for (int i = 0; i < N; i++)
	{
		long long sum = (B[N] - B[i + 1]) % mod;
 
		ans += A[i] * sum;
		ans %= mod;
	}
 
	cout << ans << endl;
}
   