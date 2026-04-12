#include <iostream>
using namespace std;
long long b[3001][3001];

int main() 
{
	int n;
	cin >> n;
	long long a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i++)
	{
		b[i][i] = a[i];
		for (int j = i - 1; j >= 1; j--)
			b[j][i] = max(a[i] - b[j][i - 1], a[j] - b[j + 1][i]);
	}
	
	cout << b[1][n];
}