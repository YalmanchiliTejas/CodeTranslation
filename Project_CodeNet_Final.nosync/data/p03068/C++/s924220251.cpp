#include<iostream>
#include<string>
using namespace std;
int main() {
	int a, b;
	char ss;
	string s;
	cin >> a >> s >> b;
	ss = s[b-1];
	for (int i = 0; i < a; ++i) {
		if (s[i] != ss)cout << "*";
		else cout << s[i];
	}
	cout << endl;
	return 0;
}