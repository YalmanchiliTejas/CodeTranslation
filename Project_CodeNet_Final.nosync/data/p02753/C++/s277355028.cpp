// g++ -std=gnu++1y -O2 main.cpp

#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>
#include <iostream>
#include <climits>

using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
	string S;
	cin >> S;

	char c = S[0];
	for (int i = 1; i < S.size(); i++)
	{
		if (S[i] != c) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}