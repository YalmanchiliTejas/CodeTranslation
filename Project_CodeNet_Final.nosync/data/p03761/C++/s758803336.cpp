#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	vector<multiset<char>> ss;

	cin >> n;
	ss.resize(n);

	if (n == 1) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		cout << s << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
			ss[i].insert(s[j]);
	}

	multiset<char> ans;
	set_intersection(ss[0].begin(), ss[0].end(),
					 ss[1].begin(), ss[1].end(),
					 inserter(ans, ans.end()));
	for (int i = 2; i < n; i++) {
		multiset<char> tmp(ans.begin(), ans.end());

		ans.erase(ans.begin(), ans.end());
		set_intersection(ss[i].begin(), ss[i].end(),
						 tmp.begin(), tmp.end(),
						 inserter(ans, ans.end()));
	}

	for_each(ans.begin(), ans.end(), [](char x) {
		cout << x;
	});
	cout << endl;
}

