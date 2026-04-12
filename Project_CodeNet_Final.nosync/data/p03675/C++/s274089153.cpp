#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> a(n), res;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int t = n - 1;
	while (t >= 0)
	{
		res.push_back(t);
		t -= 2;
	}
	t = -t - 1;
	while (t < n)
	{
		res.push_back(t);
		t += 2;
	}

	for (int i = 0; i < n; i++)
		res[i] = a[res[i]];
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], " \n"[i == n - 1]);

	return 0;
}