#include<bits/stdc++.h>
using namespace std;

int main() {
 	string s;
	cin >> s;

	map<char, int> cnt;
	for (auto u : s) cnt[u]++;
	if (cnt['A'] && cnt['B']) cout << "Yes\n";
	else cout << "No\n";
}