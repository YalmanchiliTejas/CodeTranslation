#include <bits/stdc++.h>
using namespace std;
map<char, int> used;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	used[s[0]]++;
	used[s[1]]++;
	used[s[2]]++;
	if(used['A'] && used['B'])cout << "Yes"; else cout << "No";
	return 0;
}