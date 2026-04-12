#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int n;
vector<P> ans;

signed main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			string s;
			for (int k = 0; k < n; k++) {
				if (k == i || k == j) s += '1';
				else s += '0';
			}
			cout << "? " << s << endl; cout.flush();
			
			int d;
			cin >> d;
			if (d == 1) { ans.push_back(P(i, j)); }
			if (ans.size() == n - 1) { goto ANSWER; }
		}
	}
	
ANSWER:
	cout << "!";
	for (int i = 0; i < ans.size(); i++) {
		cout << " (" << ans[i].first << "," << ans[i].second << ")";
	}
	cout << endl;
	return 0;
}
