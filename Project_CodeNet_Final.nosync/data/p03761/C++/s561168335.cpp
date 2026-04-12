#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
#include<utility>
#include<stack>
#include<queue>
#include<cmath>
#include<list>
#include<cstdint>
#include<vector>
#include<map>
#include<deque>
#define rep(i,rept)	for(int i = 0; i<(int)rept;++i)
typedef long long ll;
const ll MOD = 1e9 + 7;
using namespace std;

int main() {
	//10日目

	cin.tie(0); ios::sync_with_stdio(false);

	int n = 0,count = 0;
	int out = 114514;
	string s[50] = {};
	cin >> n;
	rep(i, n) {
		cin >> s[i];
	}

	for (int i = 'a'; i <= 'z'; i++) {

		for (int j = 0; j < n; j++) {

			for (int k = 0; k < s[j].size(); k++) {
				if (s[j][k] == i) {
					count++;
				}
			}

			out = std::min(out, count);

			count = 0;

		}

		std::cout << string(out, i);

		out = 114514;

	}
	cout << endl;

	return 0;
}
