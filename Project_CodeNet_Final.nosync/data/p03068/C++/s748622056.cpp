#include <iostream>

using namespace std;


int main() {
	string s;
	int n, k;
	char t;
	cin >> n >> s >> k;
	t = s.at(k - 1);
	for (int i = 0; i < n; i++) {
		if (!(s.at(i) == t)) {
			s.at(i) = '*';
		}
	}
	cout << s << endl;
	
}

