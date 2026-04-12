#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<climits>
#include<map>
#include<string>
#include<functional>
#include<iomanip>
#include<deque>

using namespace std;
typedef long long ll;

vector<ll> leftKey = { 1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,0,1 };
vector<ll> ans;

int main() {
	while (1) {
		char S[40] = {};
		ll counter = 0;
		cin >> S;
		if (S[0] == '#')break;
		for (int i = 1; i <= 32; i++) {
			if (S[i] == 0)break;
			if (leftKey[S[i] - 'a'] != leftKey[S[i - 1] - 'a'])counter++;
		}
		ans.push_back(counter);
	}
	for (int i = 0; i < ans.size(); i++)cout << ans[i] << endl;
	return 0;
}
