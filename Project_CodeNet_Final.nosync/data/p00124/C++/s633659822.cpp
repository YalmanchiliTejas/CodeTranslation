#include<iostream>
#include<string>
using namespace std;
string s[1000000];
int a[1000000][3], score[1000000], cnt;
int n;
int main() {
	while (true) {
		cin >> n;
		if (!n) { break; }
		if (cnt) { cout << endl; }
		cnt++;
		for (int i = 0; i < n; i++) {
			cin >> s[i] >> a[i][0] >> a[i][1] >> a[i][2];
			score[i] = a[i][0] * 3 + a[i][2];
		}
		for (int j = 100000; j >= 0; j--) {
			for (int k = 0; k < n; k++) {
				if (score[k] == j) {
					cout << s[k] << ',' << score[k] << endl;
				}
			}
		}
	}
}