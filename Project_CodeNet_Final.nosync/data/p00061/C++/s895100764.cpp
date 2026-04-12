#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<pair<int, int> > vii;
	int a, b, d;
	char c;
	while (cin >> a >> c >> b) {
		if (a == 0 && b == 0) {
			break;
		}
		vii.push_back(make_pair(b, a));
	}
	std::sort(vii.begin(), vii.end(), greater<pair<int, int> >());

	int n = vii.size();
	int ans = 1;
	vector<int> num(105);
	num[vii[0].second] = 1;
	for (int i = 0; i < n - 1; ++i) {
		if (vii[i].first != vii[i + 1].first)
			ans++;
		num[vii[i + 1].second] = ans;
	}
	while (cin >> d) {
		cout << num[d] << endl;
	}

}