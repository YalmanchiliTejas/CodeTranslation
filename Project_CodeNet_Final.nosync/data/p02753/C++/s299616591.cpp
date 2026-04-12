#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int a, b;
	a = b = 0;
	for (int i = 0;i < s.size();i++) {
		if (s[i] == 'A')a++;
		else if (s[i] == 'B')b++;
	}
	if (a==3 || b==3)cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}