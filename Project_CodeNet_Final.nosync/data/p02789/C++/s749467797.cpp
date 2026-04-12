#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
typedef long long ll;

using namespace std;

int main()
{
	cin.tie(0);
  ios::sync_with_stdio(false);
	int n, m;

	cin>>n>>m;
	if (n == m) {
		cout << "Yes";
	} else {
		cout << "No";
	}

	return 0;
}
