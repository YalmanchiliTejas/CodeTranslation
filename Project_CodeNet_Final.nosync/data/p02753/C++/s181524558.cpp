#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 7;
int main() {
	string s;
	cin >> s;
	int a = 0, b = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'A') a++;
		else b++;
	}
	if(a == 0 || b == 0) printf("No\n");
	else printf("Yes\n");
	return 0;
}
