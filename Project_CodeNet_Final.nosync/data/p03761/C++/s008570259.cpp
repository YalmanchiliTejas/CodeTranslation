#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647

int main() {
	int N;
	cin >> N;
	vector<priority_queue<char, vector<char>, std::greater<char>>> vec(N);
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (size_t t = 0; t < s.length(); ++t) {
			vec[i].push(s[t]);
		}
	}

	map<int, int> mp;
	for (int ascii = (int)'a'; ascii <= (int)'z'; ++ascii) {
		int minCount = INT_MAX;
		for (int i = 0; i < N; ++i) {
			int count = 0;
			while (!vec[i].empty() && (int)vec[i].top() == ascii) {
				++count;
				vec[i].pop();
			}
			minCount = min(minCount, count);
		}

		mp[ascii] = minCount;
	}

	string s = "";
	for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
		for (int i = 0; i < iter->second; ++i) {
			s += char(iter->first);
		}
	}

	cout << s << endl;
	return 0;
}