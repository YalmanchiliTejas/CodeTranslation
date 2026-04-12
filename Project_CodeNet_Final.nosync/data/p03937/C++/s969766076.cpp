#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int x, y;
	cin >> x >> y;
	int count = 0;
	for (int i = 0; i < x; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < y; j++) {
			count += str[j] == '#';
		}
	}
	cout << (count==x+y-1 ? "Possible" : "Impossible");
	return 0;
}