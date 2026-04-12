// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	string s;
	cin >> s;
	int cnt[256] = {};
	for (char c : s) {
		cnt[c] += 1;
	}
	bool ans = cnt['A'] > 0 && cnt['B'] > 0;
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
