#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <numeric>
#include <set>
#define FOR(i, a, n) for (int i = (a); i < (n); i++)
#define REP(i, n) for(int i = 0; i < (n); i++)
using namespace std;



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S;
	int N, K;

	cin >> N >> S >> K;

	REP(i, S.length())
	{
		if (S[i] != S[K - 1])
		{
			S[i] = '*';
		}
	}

	cout << S << endl;

	return 0;
}