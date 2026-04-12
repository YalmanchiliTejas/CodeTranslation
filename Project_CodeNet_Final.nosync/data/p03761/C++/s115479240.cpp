#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;
	int b[30];
	for (int i = 0; i < 30; ++i) {
		b[i] = 100;
	}
	string S[51];
	for (int i = 0; i < n; ++i) {
		cin >> S[i];
		int a[30] = { 0 };
		for (int j = 0; j < S[i].size();++j) {
			int x = S[i][j] - 'a';
			a[x]++;
		}
		for (int j = 0; j < 26; ++j) {
			b[j] = min(b[j], a[j]);
		}
	}
	for (char i = 'a'; i <= 'z'; ++i) {
		for (int j = 0; j < b[i - 'a']; ++j) {
			cout << i;
		}
	}
	cout << endl;
	return 0;
}
