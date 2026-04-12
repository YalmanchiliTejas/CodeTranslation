#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include<math.h>
#include<bitset>
#include<iomanip>
using namespace std;

int main() {
	int n; cin >> n;
	vector<string> s(n);
	int x[50][50] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++) {
			int y = s[i][j];
			x[i][y-'a']++;
		}
	}

	vector<int> mi(30, 10000);
	for (int i = 0; i <='z'-'a'; i++) {
		for (int j = 0; j < n; j++) {
			mi[i] = min(mi[i], x[j][i]);
		}
	}
	string ans;
	for (int i = 0; i <= 'z'-'a'; i++) {
		for (int j = 0; j < mi[i]; j++) {
			ans.push_back((char)(i+'a'));
		}
	}
	cout << ans << endl;
}

