#include <iostream>
#include <string>

using namespace std;


int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int k;
	cin >> k;
	k--;
	string answer = "";

	for (int i = 0; i < n; i++) {
		if (s.substr(i, 1) == s.substr(k, 1)) {
			answer += s.substr(k, 1);
		}
		else {
			answer += "*";
		}
	}

	cout << answer << endl;

    return 0;
}