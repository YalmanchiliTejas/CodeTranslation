#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<iomanip>
#include<functional>
using namespace std;

int INF = 1e9 + 7;

typedef long long ll;
typedef pair<int, int> P;

int main() {
	int n;
	cin >> n;
	vector<string> s(n + 1);
	vector<vector<int>> same(n + 1, vector<int>(30, 0));

	for (int i = 1; i <= n; i++) {
		cin >> s[i];

		for (char j = 'a'; j <= 'z'; j++) {
			for (int k = 0; k < s[i].size(); k++) {
				if (s[i][k] == j) same[i][j-'a'+1] += 1;
			}
		}
	}

	string ans;
	for (char i = 'a'; i <= 'z'; i++) {
		int MIN = INF;

		for (int j = 1; j <= n; j++) {
			MIN = min(MIN, same[j][i-'a'+1]);
		}

		for (int j = 1; j <= MIN; j++) {
			ans.push_back(i);
		}
	}
	cout << ans << endl;
}