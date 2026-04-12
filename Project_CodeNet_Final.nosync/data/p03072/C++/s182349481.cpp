#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> H(N);
	for (int i = 0; i < N; i++)
	{
		cin >> H[i];
	}

	int count = 1;
	int maxH = H[0];

	for (int i = 1; i < N; i++)
	{
		if (H[i] >= maxH) count++;
		maxH = max(maxH, H[i]);
	}

	cout << count << endl;
}