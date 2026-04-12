#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;

const string LEFT_TYPES = "qwertasdfgzxcvb";

int main(void) {
	string str;
	while (getline(cin, str), str != "#") {
		int changeNum = 0;
		bool handIsLeft = LEFT_TYPES.find(str[0], 0) != string::npos;
		for (int i = 1; i < str.size(); i++) {
			bool now = LEFT_TYPES.find(str[i], 0) != string::npos;
			if (handIsLeft != now) {
				handIsLeft = now;
				changeNum++;
			}
		}
		cout << changeNum << endl;
	}

	return 0;
}