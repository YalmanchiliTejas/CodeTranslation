#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int count = 1;
	int count2 = 0;
	vector<int> H(N);
	for (int i = 0; i < N; i++)
	{
		cin >> H.at(i);
	}
	int maxv = *max_element(H.begin(), H.end());
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
			{
				count2 = 0;
				break;
			}
			if (H.at(j) <= H.at(i))
			{
				count2++;
			}
			if (count2 == i && H.at(i - 1) <= H.at(i))
			{
				count++;
			}
		}
	}
	cout << count << endl;
}