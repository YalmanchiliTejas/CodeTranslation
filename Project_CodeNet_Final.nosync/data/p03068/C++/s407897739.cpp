#include<iostream>
#include<algorithm>
#include<vector>
#include<string>


using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int K;
	cin >> K;

	char c = s.at(K - 1);

	for (int i = 0; i < n; i++) {
		if (c == s.at(i)) {
			continue;
		}
		else {
			s.at(i) = '*';
		}
	}

	cout << s << endl;
}