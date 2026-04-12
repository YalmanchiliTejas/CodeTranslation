#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <queue>
#include <list>
#include <cstdlib>
#include <cmath>

#define _USE_MATH_DEFINES
#define REP(i,n) for(int i = 0;i<n;i++);

using namespace std;

int main() {

	char cap;

	cin >> cap;
	if (cap == 'a' || cap == 'i' || cap == 'u' || cap == 'e' || cap == 'o') {
		cout << "vowel" << endl;
	}
	else
		cout << "consonant" << endl;

	return 0;
}

