#include <bits/stdc++.h>
using namespace std;

const int N = 110;

char str[N];

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> str;
	int len = strlen(str);
	for (int i = 1; i < len; i++) if (str[i - 1] == 'A' && str[i] == 'C') {
		cout << "Yes\n";
		return 0;
	}
	cout << "No\n";
	
	return 0;
}
