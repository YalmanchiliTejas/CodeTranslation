#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for (int i = a; i < b; i++)
using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <tuple>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
#include <bitset>

int main() {
	char c;
	cin >> c;

	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		cout << "vowel" << endl;	
	}
	else {
		cout << "consonant" << endl;	
	}
}