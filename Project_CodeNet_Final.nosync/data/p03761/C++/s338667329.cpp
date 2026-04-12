#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<vector<int>>s(n, vector<int>(26,0));
	for (int i = 0; i < n; i++) {
		string v;
		cin >> v;
		for (int j = 0; j < v.length(); j++)s.at(i).at((int)v.at(j) - 'a')++;
	}
	vector<int>a(26,100);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			a.at(j) = min(a.at(j), s.at(i).at(j));
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < a.at(i); j++) {
			char x = 'a' + i;
			cout << x;
		}
	}
	cout << endl;
}