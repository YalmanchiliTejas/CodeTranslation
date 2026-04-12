#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	/* time: O(1), space: O(1) */
	bool stationAndBus(const string& s) {
		return (s != "AAA") && (s != "BBB");
	}
};

int main() {
	string s;
	cin >> s;

	Solution sol;
	const bool ans = sol.stationAndBus(s);
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
