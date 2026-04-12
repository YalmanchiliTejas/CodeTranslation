#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> s(N);
	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
	}

	long long ans = 0;
	vector<int> flag(N, 0);
	for (int i = 1; i < N; i++)
	{
		long long sum = 0;
		for (int j = 0; j < N - i; j += i)
		{
			int k = N - 1 - j;

			if (flag[j] == i) break;
			flag[j] = i;
			sum += s[j];

			if (flag[k] == i) break;
			flag[k] = i;
			sum += s[k];

			ans = max(ans, sum);
		}
	}
	cout << ans << endl;
	cin >> ans;
}

