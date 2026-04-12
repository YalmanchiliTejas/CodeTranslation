#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <tuple>
#include<map>

using namespace std;
int main() {
	char c;
	cin >> c;

	bool ans = false;

	switch (c) {
	case 'a':
		ans = true;
		break;
	case 'i':
		ans = true;
		break;
	case'u':
		ans = true;
		break;
	case'e':
		ans = true;
		break;
	case'o':
		ans = true;
		break;
	}
	
	if (ans) {
		cout << "vowel" << endl;
	}else{
		cout << "consonant" << endl;
	}

}