#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
   


int main() {
	string s;

	cin >> s;
	sort(s.begin(), s.end());
	if (s[0] == s[2]) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}


	return 0;
}