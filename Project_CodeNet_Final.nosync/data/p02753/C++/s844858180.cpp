#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)

int main()
{
	string s;
	cin >> s;
	if (s.at(0) == s.at(1)) {
		if (s.at(1) == s[2]) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
	return 0;
}