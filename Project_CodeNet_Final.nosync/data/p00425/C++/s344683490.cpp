#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		int d[6] = { 1, 2, 3, 4, 5, 6 };
		string s;
		int sum = 1;
		for (int i = 0; i < n; i++) {
			cin >> s;
			int t;
			if (s == "North") {
				t=d[0], d[0]=d[1], d[1]=d[5], d[5]=d[4], d[4]=t;
			} else if (s == "South") {
				t=d[0], d[0]=d[4], d[4]=d[5], d[5]=d[1], d[1]=t;
			} else if (s == "East") {
				t=d[0], d[0]=d[3], d[3]=d[5], d[5]=d[2], d[2]=t;
			} else if (s == "West") {
				t=d[0], d[0]=d[2], d[2]=d[5], d[5]=d[3], d[3]=t;
			} else if (s == "Right") {
				t=d[1], d[1]=d[2], d[2]=d[4], d[4]=d[3], d[3]=t;
			} else if (s == "Left") {
				t=d[1], d[1]=d[3], d[3]=d[4], d[4]=d[2], d[2]=t;
			}
			sum += d[0];
		}
		cout << sum << endl;
	}
	return 0;
}