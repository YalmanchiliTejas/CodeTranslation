#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> x;

int main(int, char**)
{
	ll a, b, k, ans = 0;
	string s;
	cin >> a >> s >> k;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] != s[k-1]) cout << '*';
		else cout << s[i];
	}
	cout << endl;

	return 0;
}
 