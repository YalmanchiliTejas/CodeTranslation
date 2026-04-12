#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define ll long long
#define INF (1<<30)
using namespace std;
int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<vector<int>> S(n, vector<int>(27, 0));
	vector<int> ans(27, INF);
	for (int i = 0; i < n;i++) {
		string s; cin >> s;
		for (auto c : s) {
			S[i][c - 'a']++;
		}
	}
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < 27;j++) {
			ans[j] = min(S[i][j], ans[j]);
		}
	}
	string s_ans = "";
	for (int i = 0; i < 27;i++) {
		if(ans[i] !=0)
			s_ans += string(ans[i], 'a'+i);
	}
	cout << s_ans << endl;
}