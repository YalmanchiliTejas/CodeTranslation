#include<bits/stdc++.h>
using namespace std;
int main() {
	string str;
	cin >> str;
	int a = 0, b = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'A') {
			a++;
		} else {
			b++;
		}
	}
	if (a > 0 && b > 0)
		cout << "Yes\n";
	else
		cout << "No\n";
}