#include<cstdio>
#include <iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<functional>
#include<cmath>
#include<map>
#include<stack>
#include<cstdlib>
#include<list>
#include<set>
#include<numeric>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main()
{
	int N; cin >> N;
	vector<string> str;
	string s, ans;

	for (int i = 0; i < N; i++) {
		cin >> s;
		str.push_back(s);
	}

	for (int i = 0; i < str[0].length(); i++) {
		int cnt = 0;
		for (int j = 1; j < str.size(); j++) {
			for (int k = 0; k < str[j].length(); k++) {
				if (str[0][i] == str[j][k]) {
					cnt++;
					str[j][k] = '0';
					break;
				}
			}
		}
		if (cnt == N - 1)ans += str[0][i];
	}
	sort(ans.begin(),ans.end());
	cout << ans << endl;
	return 0;
}