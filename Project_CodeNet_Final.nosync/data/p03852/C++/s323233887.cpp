#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char **argv) {
	char s;
	cin >> s;
	if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
		cout << "vowel\n";
	else
		cout << "consonant\n";
	return 0;
}
