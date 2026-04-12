#include <iostream>
#include <string>

using namespace std;


int main() {
	string s;
	int N, K;
	cin >> N >> s >> K;
	char c = s[K-1];

	for(auto &x: s) {
		if(x != c) x = '*';
	}

	cout << s << endl;
}
