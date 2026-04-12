#include <iostream>
using namespace std;

int n, s, a;
long long b[3001][3001], c[3001][3001];
const long long M = 998244353;

int main()
{
	cin >> n >> s;

	for (int i = 1; i <= n; i++) {
		cin >> a;

		b[i][0] = 1;
		c[i][0] = 1;
		b[i][a] = 1;
		c[i][a] = 1;

		for (int j = 0; j <= s; j++) {
			b[i][j] = (b[i][j] + b[i - 1][j]) % M;
			c[i][j] = (c[i][j] + b[i - 1][j] + c[i - 1][j]) % M;

			if (j >= a) {
				b[i][j] = (b[i][j] + b[i - 1][j - a]) % M;
				c[i][j] = (c[i][j] + b[i - 1][j - a]) % M;
			}
		}
	}

	cout << c[n][s] << endl;	
}
