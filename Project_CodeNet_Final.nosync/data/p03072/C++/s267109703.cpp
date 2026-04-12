#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	int n; cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) cin >> h[i];

	int cnt = 1;
	int i=0, j=0;

	for (int i = 1; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (h[i] < h[j])
			{
				break;
			}
		}
		if (i == j)
		{
			cnt++;
		}
	}

	cout << cnt << endl;
}
