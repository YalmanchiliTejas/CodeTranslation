//冷静に考えるとk=1, n-1しか必要なくて、数列を回しながらバブルソートするだけ。
#include <iostream>
#include <vector>
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

int n;
int p[200];
vector<int> ans;

int main() {
	int i, j;
	
	cin >> n;
	rep(i, n - 1) cin >> p[i + 1];
	cin >> p[0];
	
	rep(i, n) {
		int hanten = 0;
		for (j = 0; j < n - 1; j++) {
			if (p[j] > p[j + 1]) {
				swap(p[j], p[j + 1]);
				ans.push_back(n - 1);
				hanten++;
			}
			ans.push_back(1);
		}
		if (hanten == 0) break;
		ans.push_back(1);
	}
	
	cout << ans.size() << endl;
	rep(i, ans.size()) {
		cout << ans[i] << endl;
	}
	return 0;
}