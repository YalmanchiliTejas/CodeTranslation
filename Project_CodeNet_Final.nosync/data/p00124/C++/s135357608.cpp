#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
using namespace std;
typedef unordered_set<string> US;
typedef vector<string> VS;

int main() {
	int n;
	int lp = 0;
	while (cin >> n, n) {
		VS v[30];
		if (lp != 0)cout << endl;

		for (int i = 0;i < n;i++) {
			string s;
			int a, b, c;
			cin >> s >> a >> b >> c;
			int p = 3 * a + c;
			v[p].push_back(s);
		}

		for (int i = 29;i > -1;i--) {
			for (auto itr = v[i].begin();itr != v[i].end();itr++) {
				cout << *itr << ',' << i << endl;
			}
		}
		lp++;
	}
	return 0;
}