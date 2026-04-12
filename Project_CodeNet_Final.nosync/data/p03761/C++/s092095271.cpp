#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> S(n);
	for (auto& x : S) {
		cin >> x;
		sort(x.begin(), x.end());
	}
	string ans = S[0];
	for (int i = 1; i < n; ++i) {
		string tmp;
		set_intersection(ans.begin(), ans.end(), S[i].begin(), S[i].end(), back_inserter(tmp));
		ans = tmp;
	}
	cout << ans << endl;
}
