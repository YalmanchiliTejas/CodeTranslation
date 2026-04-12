#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; a *= -1;
		if (v.empty() || v.back() <= a) v.push_back(a);
		else (*upper_bound(v.begin(), v.end(), a)) = a;
	}
	cout << v.size() << '\n';
	return 0;
}	