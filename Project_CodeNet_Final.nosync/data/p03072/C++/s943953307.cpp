#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#define numarr 22
using namespace std;

int main() {
	int N, H[numarr], ans = 0, i, j;
	cin >> N;
	for (i = 1; i <= N; i++)
	{
		cin >> H[i];
		j = 1;
		while (1)
		{
			if (H[j] > H[i])
				break;
			if (j == i)
			{
				ans++;
				break;
			}
			j++;
		}
	}
	cout << ans << endl;
}