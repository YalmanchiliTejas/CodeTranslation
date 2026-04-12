#include<iostream>
#include<map>
#include<string>
using namespace std;
int main() {
	int n;
	while (cin >> n&&n != 0) {
		string s;
		int a[3] = { 1,2,3 }, sum = 1;
		for (int i = 0; i < n; i++) {
			cin >> s;
			if (s == "North") {
				int b = a[1];
				a[1] = 7 - a[0];
				a[0] = b;
			}
			else if (s == "East") {
				int b = a[0];
				a[0] = 7 - a[2];
				a[2] = b;
			}
			else if (s == "West") {
				int b = a[2];
				a[2] = 7 - a[0];
				a[0] = b;
			}
			else if (s == "South") {
				int b = a[0];
				a[0] = 7 - a[1];
				a[1] = b;
			}
			else if (s == "Right") {
				int b = a[2];
				a[2] = 7 - a[1];
				a[1] = b;
			}
			else if (s == "Left") {
				int b = a[1];
				a[1] = 7 - a[2];
				a[2] = b;
			}
			sum += a[0];
		}
		cout << sum << endl;
	}
}