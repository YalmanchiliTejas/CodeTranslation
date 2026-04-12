#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;

int main() {
	vector<int> e(12, 0);
	string ans = "no";
	for (int i = 0; i < 12; i++) {
		int temp;
		cin >> temp;
		e[i] = temp;
	}
	sort(e.begin(), e.end());

	if (e[0] == e[1] && e[1] == e[2] && e[2] == e[3]) {
		if (e[4] == e[5] && e[5] == e[6] && e[6] == e[7]) {
			if(e[8] == e[9] && e[9] == e[10] && e[10] == e[11])
			ans = "yes";
		}
	}
	cout << ans << endl;
	return 0;

}