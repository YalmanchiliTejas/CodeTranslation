#include <string>
#include <iostream>
using namespace std;
int L; string s, t;
int main() {
	cin >> L >> s >> t;
	if (s > t) swap(s, t);
	if (t.substr(0, s.size()) != s) {
		if (s > t) swap(s, t);
	}
	else {
		string ca = s, cb = t;
		while (ca.size() < 10000000) ca += s;
		while (cb.size() < 10000000) cb += s;
		if (ca > cb) swap(s, t);
	}
	int b = 0, bb = 0;
	for (int i = 0; i <= L; i += s.size()) {
		if ((L - i) % t.size() == 0) {
			b = i / s.size();
			bb = (L - i) / t.size();
		}
	}
	for (int i = 0; i < b; i++) cout << s;
	for (int i = 0; i < bb; i++) cout << t;
	cout << endl;
	return 0;
}