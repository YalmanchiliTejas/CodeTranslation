#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s[55];
	int co[26], co1[26] = { 0 };
	for (int s1 = 0; s1 < 26; s1++) {
		co[s1] = 1000000007;
	}
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++) {
			co1[int(s[i][j] - 'a')]++;
		}
		for (int k = 0; k < 26; k++) {
			if (co[k] > co1[k]) {
				co[k] = co1[k];
			}
			co1[k] = 0;
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < co[i]; j++) {
			cout << char(i + 'a');
		}
	}
	cout << endl;
	return 0;
}