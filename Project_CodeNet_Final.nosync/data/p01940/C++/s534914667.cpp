#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

string T, P;
vector<int> v1, v2;
int main(void) {
	cin >> T >> P;
	bool ans = false;
	int ind = 0;
	for (int i = 0; i < T.size() && ind < P.size(); i++) {
		if (T[i] == P[ind]) {
			v1.push_back(i);
			ind++;
		}
	}
	if (v1.size() == P.size()) {
		ind--;
		for (int i = T.size()-1; i >= 0 && ind >= 0; i--) {
			if (T[i] == P[ind]) {
				v2.push_back(i);
				ind--;
			}
		}
		reverse(v2.begin(), v2.end());
		ans = v1 == v2;
	}
	cout << (ans ? "yes" : "no") << endl;
}