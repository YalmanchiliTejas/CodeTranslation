#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	if (n <= m)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}