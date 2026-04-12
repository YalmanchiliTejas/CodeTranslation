#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	bool ac = 0;
	for (int i = 0; i < (int) s.length() - 1; ++ i) if (s[i] == 'A' && s[i + 1] == 'C') ac = 1;
	puts(ac ? "Yes" : "No");
}
