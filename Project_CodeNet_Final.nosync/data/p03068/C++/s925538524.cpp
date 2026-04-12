#include<iostream>
using namespace std;
int main() {
	int n,k;
	char s[11],x;
	cin >> n ;
	for (int i = 0; i < n; ++i) cin >> s[i];
	cin >> k;
	x = s[k - 1];
	for (int i = 0; i < n; ++i)
		if (x != s[i]) s[i] = '*';
	for (int i = 0; i < n; ++i) cout<< s[i];
	cout << endl;
	return 0;
}