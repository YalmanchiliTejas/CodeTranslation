#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<cmath>
#include<map>
using namespace std;
#define int long long
#define inf   1000000009
#define minf -1000000009

signed main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == 'A'&&s[i + 1] == 'C') {
			puts("Yes");
			return 0;
		}
	}
	puts("No");
}