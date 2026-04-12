#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main() {
	vector<map<double,string>>t(0);
	while (1) {
		int k;
		cin >> k;
		if (k == 0)break;	
			map<double, string>s;
			auto c = 0.01;
			for (int b = 0; b < k; b++) {
				string d; double e, f, g;
				cin >> d >> e >> f >> g;
				s.insert(pair<double, string>((e * 3 + f * 0 + g * 1 + (1 - c)), d));
				c += 0.01;
			}
			t.push_back(s);
	}
	for (int u = 0; u < t.size(); u++) {
		auto y = t[u].end(); y--;
		for (;; y--) {
			cout << y->second << "," <<(int) y->first << endl;
			if (y == t[u].begin())break;
		}
		if (t.size() - 1 != u)cout << endl;
	}
}