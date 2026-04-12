/*
 * main.cpp
 *
 *  Created on: 2017/10/22
 *      Author: sep
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

inline int main001();
inline int main002();
inline int main003();
inline int main004();

//#define TEST

int main() {

#ifdef TEST
	while (1)
#endif
		main001();

	return 0;
}

inline int main001() {

	string input;

	cin >> input;

	if (input.find("AC") == -1) {
		cout << "No";
	} else {
		cout << "Yes";
	}

	return 0;

}
