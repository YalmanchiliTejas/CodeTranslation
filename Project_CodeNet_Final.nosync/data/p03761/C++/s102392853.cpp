#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string>s(n);
	string common_trial, common_ans;
	cin >> s[0];
	sort(s[0].begin(), s[0].end());
	common_trial = s[0];
	for (int i = 1; i < n; ++i) {
		cin >> s[i];
		sort(s[i].begin(), s[i].end());
		int h = 0;
		for (int j = 0; j < common_trial.size(); ++j) {
			for(int k=h;k<s[i].size();++k){
				if (common_trial[j] == s[i][k]) {
					common_ans.push_back(s[i][k]);
					h = k+1;
					break;
				}
			}
		}
		common_trial = common_ans;
		common_ans = "";
	}
	cout << common_trial << endl;
	return 0;
}