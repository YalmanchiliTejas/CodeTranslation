#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <unordered_map> //C++11
using namespace std;

typedef long long ll;

int main() {
	int n;
	string s[50];
	unordered_map<string, int> mp[50];
	string alp = "abcdefghijklmnopqrstuvwxyz";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < alp.length(); j++) mp[i][alp.substr(j, 1)] = 0;
		for (int j = 0; j < s[i].length(); j++) {
			mp[i][s[i].substr(j, 1)] += 1;
		}
	}
	for (int i = 0; i < alp.length(); i++) {
		int min = 10000;
		for (int j = 0; j < n; j++) {
			if (mp[j][alp.substr(i, 1)] < min) min = mp[j][alp.substr(i, 1)];
		}
		for (int j = 0; j < min; j++) cout << alp.at(i);
	}
	cout << endl;
	return 0;
}
