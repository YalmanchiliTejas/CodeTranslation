#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int32_t n;
	cin >> n;

	vector<int32_t> cnt_min(26);
	fill(begin(cnt_min), end(cnt_min), numeric_limits<int32_t>::max());

	for (int32_t i = 0; i  < n; i++) {
		string S;
		cin >> S;
		vector<int32_t> cnt(26);
		fill(begin(cnt), end(cnt), 0);
		for (size_t j = 0; j  < S.size(); j++) {
			cnt[S[j] - 'a']++;
		}
		for (int32_t j = 0; j  < 26; j++) {
			cnt_min[j] = min(cnt_min[j], cnt[j]);
		}
	}

	for (int32_t i = 0; i  < 26; i++) {
		for (int32_t j = 0; j  < cnt_min[i]; j++) {
			cout << (char)('a' + i);
		}
	}

	cout << endl;

	return 0;
}