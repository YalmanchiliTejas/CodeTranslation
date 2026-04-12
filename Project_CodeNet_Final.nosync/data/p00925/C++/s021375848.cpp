#include<iostream>
#include<string>
using namespace std;
int ctoi(char c) {
	int i; char ch = '0';
	for (i = 0; i < 10; i++){
		if (c == ch)return i;
		else ch++;
	}
	return -1;
}
int main() {
	string s; cin >> s;
	int ans1 = 0, ans2, anss = 0;
	for (int i = 0; i < s.size(); i += 2) {
		if (i == 0) { anss = ctoi(s[i]); ans2 = ctoi(s[i]); }
		else if (i % 2 == 0) {
			if (s[i - 1] == '+') {
				ans1 += anss;
				anss = ctoi(s[i]);
				ans2 += ctoi(s[i]);
			}
			else {
				anss *= ctoi(s[i]);
				ans2 *= ctoi(s[i]);
			}
		}
	}
	ans1 += anss;
	int v; cin >> v;
	if (ans1 == v) {
		if (ans2 == v)
			cout << "U\n";
		else
			cout << "M\n";
	}
	else {
		if (ans2 == v)
			cout << "L\n";
		else
			cout << "I\n";
	}
}