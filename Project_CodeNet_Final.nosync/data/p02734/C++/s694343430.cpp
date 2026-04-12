#include <vector>
#include <iostream>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int N, S;
vector<int> A;

int main (void)
{
	cin >> N >> S;
	A.resize (N);
	for (auto& e: A)
		cin >> e;

	vector<vector<vector<ll>>> DynamicP (N+1);
	for (auto& e: DynamicP)
	{
		e.resize (S+1);
		for (auto& e2: e)
			e2.resize (3);

	}
	DynamicP[0][0][0] = 1;
	for (int i = 0; i < N; i++)
		for (int s = 0; s <= S; s++)
		{
			(DynamicP[i+1][s][0] += DynamicP[i][s][0]) %= mod;
			(DynamicP[i+1][s][1] += DynamicP[i][s][0] + DynamicP[i][s][1]) %= mod;
			(DynamicP[i+1][s][2] += DynamicP[i][s][0] + DynamicP[i][s][1] + DynamicP[i][s][2]) %= mod;
			if (s + A[i] <= S)
			{
				(DynamicP[i+1][s+A[i]][1] += DynamicP[i][s][0] + DynamicP[i][s][1]) %= mod;
				(DynamicP[i+1][s+A[i]][2] += DynamicP[i][s][0] + DynamicP[i][s][1]) %= mod;
			}
		}
	cout << DynamicP [N][S][2] << endl;
	return 0;
}