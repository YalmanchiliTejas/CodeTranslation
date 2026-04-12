#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD = 1000000007;

int main()
{
	int n = 0;
	cin >> n;
	string ans = "NO";
	if (n == 3 || n == 5 || n == 7)
	{
		ans = "YES";
	}
	cout << ans << "\n";
	return 0;
}