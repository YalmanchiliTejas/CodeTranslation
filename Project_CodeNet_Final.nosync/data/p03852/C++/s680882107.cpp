#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stack> // s.top()
#include <bitset>
#include <queue> // s.front()
using namespace std;

typedef long long Int;
typedef pair<Int,Int> P;

#define INF10 10000000000
#define INF5 100000
#define EPS 1e-10
#define MOD 1000000007


int main() {
	string s = "aeiou";
	char ipt;

	cin >> ipt;
	for (int i = 0; i < 5; i++) {
		if (ipt == s[i]) {
			cout << "vowel" << endl;
			return 0;
		}
	}
	cout << "consonant" << endl;



	return 0;
}