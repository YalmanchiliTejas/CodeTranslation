#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;


int main()
{
	int N;
	cin >> N;
	vector<ll>v(N);
	for (auto& i : v)cin >> i;
	vector<ll>pSum(N + 1, 0);
	pSum[0] = v[0];
	for (int i = 1; i < N; i++)pSum[i] = (pSum[i - 1] + v[i]) ;
	ll sum = 0;
	for (int i = 0; i < N - 1; i++)
	{
		sum = (sum + (v[i] * ((pSum[N - 1] - pSum[i]) % MOD)) % MOD) % MOD;
	}
	cout << sum%MOD;
}
