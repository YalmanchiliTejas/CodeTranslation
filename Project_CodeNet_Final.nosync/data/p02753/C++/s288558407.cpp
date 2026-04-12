#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define rep(i,n) for(int i = 0;i < (n); i++)

int main() {
	string s;
	cin >> s;
	int count = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'A')count++;
	}
	if (count == 0 || count == 3)cout << "No" << endl;
	else cout << "Yes" << endl;

	return 0;
}
