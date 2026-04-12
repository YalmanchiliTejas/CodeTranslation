#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	char s1 = s[0];
	char s2 = s[1];
	char s3 = s[2];

	string result = "Yes";
	if(s1 == s2 && s2 == s3) result = "No";

	cout << result << endl;

    return 0;
}
