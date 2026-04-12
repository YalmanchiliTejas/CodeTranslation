#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<sstream>
#include<iomanip>
#include<limits>
#include<deque>
#include<map>
#include<list>
#include<set>
#include <unordered_set>
#include<vector>
#include<cmath>
#include<cstdio>
#include<memory>
#include<bitset>
#include <functional>
#include <queue>

using namespace std;

constexpr int MOD = 1000000007;
constexpr int INF = 1050000000;

int main() {

	int n; cin >> n;
	string s; cin >> s;
	int k; cin >> k;

	char x = s[k - 1];

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == x) {
			cout << s[i];
		}
		else {
			cout << "*";
		}
	}

	cout << endl;






}