#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;


int main() {
	char a[3];
	cin >> a;
	char b[10] = "aiueo";
	for (int i = 0; i < 5; i++) {
		if (a[0] == b[i]) {
			cout << "vowel";
			return 0;
		}
	}
	cout << "consonant";
}