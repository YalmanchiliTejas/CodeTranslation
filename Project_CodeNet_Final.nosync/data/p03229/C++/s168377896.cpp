#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

long maxDiff(vector<int>);

int main()
{
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A.begin(), A.end());
	long ans = maxDiff(A);
	sort(A.begin(), A.end(),greater<int>());
	ans = max(ans, maxDiff(A));
	cout << ans << endl;
	return 0;
}

long maxDiff(vector<int> a)
{
	long sum = 0;
	int n = a.size();
	sum += abs(a[(n - 1) / 2] - a[n - 1]);
	for (int i = 0; i < n / 2 - 1; i++)
	{
		sum += abs(a[n - 1 - i] - a[i]);
		sum += abs(a[i] - a[n - 1 - (i + 1)]);
	}
	if (n % 2 != 0)
	{
		sum += abs(a[n - n / 2] - a[n / 2 - 1]);
	}
	return sum;
}