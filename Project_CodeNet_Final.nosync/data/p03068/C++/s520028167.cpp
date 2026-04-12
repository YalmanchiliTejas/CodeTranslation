#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main()
{
	int n, k;
	char s[10] = { 0 };
	cin >> n >> s >> k;
	for (int i = 0; i < n; i++) {
		if (s[i] == s[k - 1]) {

		}
		else { s[i] = '*'; }
	}
	for (int i = 0; i < n; i++) {
		cout << s[i];
	}
	return 0;
}