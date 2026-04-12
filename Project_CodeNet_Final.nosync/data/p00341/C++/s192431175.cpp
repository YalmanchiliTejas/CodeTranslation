#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int a[12];
string solve() {
	for (int i = 0; i < 12; i += 4) {
		for (int j = i; j < i + 4; j++) {
			for (int k = j; k < i + 4; k++) {
				if (a[j] != a[k])return "no";
			}
		}
	}
	return "yes";
}
int main() {
	for (int i = 0; i < 12; i++)cin >> a[i];
	sort(a, a + 12);
	cout << solve() << endl;
	return 0;
}