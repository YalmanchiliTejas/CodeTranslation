#define _USE_MATH_DEFINES
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<deque>
#include<list>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

int main() {
	string L = "qwertasdfgzxcvb",
		R = "yuiophjklnm";
	for (string s; cin >> s&&s != "#";) {
		int cnt = 0;
		bool l = (L.find(s[0]) != string::npos) ? true : false;
		for (int i = 0; i < s.size(); i++) {
			if (R.find(s[i]) != string::npos && l) {
				cnt++;
				l = false;
			}
			else if (L.find(s[i]) != string::npos && !l) {
				cnt++;
				l = true;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}