#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int n;
	cin >> n;

	vector<int> v(26);
	for (int i = 0; i < 26; i++) {
		v.at(i) = 10000;
	}

	for (int i = 0; i < n; i++) {
		string S;
		cin >> S;

		vector<int> v2(26);
		for (int j = 0; j < S.size(); j++) {
			int n = (int)S.at(j) - 'a';
			//cout << n << endl;
			v2.at(n)++;
		}

		//for (int j = 0; j < 26; j++) {
		//	if (j) cout << ' ';
		//	cout << v2.at(j);
		//	if (j == 25) cout << endl;
		//}

		for (int j = 0; j < 26; j++) {
			v.at(j) = min(v.at(j), v2.at(j));
		}
	}

	//for (int i = 0; i < 26; i++) {
	//	cout << i << ":" << v.at(i) << endl;
	//}

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < v.at(i); j++) {
			char ch= (char)i + 97;
			cout << ch;
		}
	}
	cout << endl;
}