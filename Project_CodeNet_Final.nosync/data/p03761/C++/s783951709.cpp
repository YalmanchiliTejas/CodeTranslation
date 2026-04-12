#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

void solve1() {
	int a, b, c;
	cin >> a >> b >> c;
	string ans = (b - a == c - b) ? "YES" : "NO";
	cout << ans << endl;
	return;
}

void solve2() {
	string O, E;
	cin >> O >> E;
	string ans = "";
	for (int i = 0; i < O.size(); i++) {
		ans += O[i];
		if (i < E.size()) {
			ans += E[i];
		}
	}
	cout << ans << endl;

}

void solve3() {
	int N;
	map<char, int> Min;
	cin >> N;
	N--;
	string s;
	cin >> s;
	map<char, int> tmp;
	for (int j = 0; j < s.size(); j++) {
		tmp[s[j]]++;
	}
	for (auto it = tmp.begin(); it != tmp.end(); it++) {
		Min[it->first] = tmp[it->first];
	}
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		map<char, int> tmp;
		for (int j = 0; j < s.size(); j++) {
			tmp[s[j]]++;
		}
		for (auto it = Min.begin(); it != Min.end(); it++) {
			Min[it->first] = min(Min[it->first], tmp[it->first]);
		}
	}
	string ans = "";
	for (auto it = Min.begin(); it != Min.end(); it++) {
		for (int i = 0; i < it->second; i++) {
			ans += it->first;
		}
	}
	cout << ans << endl;
}

int main() {
	solve3();
	return 0;
}