#include<iostream>
#include<string>
using namespace std;

char s[10];
int N, k;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}
	cin >> k;

	for (int i = 0; i < N; i++) {
		if (s[i] != s[k - 1]) {
			cout<<'*';
		}
		else {
			cout << s[i];
		}
	}
	cout << endl;
	return 0;
}