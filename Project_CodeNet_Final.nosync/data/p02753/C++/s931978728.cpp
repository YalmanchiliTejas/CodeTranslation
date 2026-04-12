#include <iostream>

using namespace std;
typedef long long llong;

void solve_test()
{
	char a, b, c;
	cin >> a >> b >> c;
	if (a == b && a != c) cout << "Yes\n";
	else if (a == c && a != b) cout << "Yes\n";
	else if (b == c && b != a) cout << "Yes\n";
	else cout << "No\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tests = 1;
	//cin >> tests;
	while (tests--)
		solve_test();

	return 0;
}
