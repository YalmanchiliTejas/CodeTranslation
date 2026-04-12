
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<iomanip>

using namespace std;

#define rep(i,n,m) for(int i=n;i<(int)(m);i++)


int main() {
	
	int n;
	cin >> n;

	vector<string>word(n);

	rep(i, 0, n)cin >> word[i];

	vector<vector<int>>spl(n, vector<int>(26, 0));
	vector<int>ans(26, 0);


	rep(i, 0, n) {
		rep(j, 0, (int)word[i].size()) {
			spl[i][word[i][j] - 'a']++;
		}
	}

	rep(i, 0, 26) {
		int cnt = 0;
		while (spl[cnt][i] > 0) {
			spl[cnt][i]--;
			if (cnt == n - 1) {
				ans[i]++;
				cnt = 0;
			}
			else cnt++;

		}
	}

	rep(i, 0, 26) {
		char c = 'a' + i;
		while (ans[i] > 0) {
			cout << c;
			ans[i]--;
		}

	}
	cout << endl;

	return 0;
}

