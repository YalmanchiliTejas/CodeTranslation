#include <iostream>
using namespace std;
string str;
signed main() {
	cin >> str;
	for (int i = 1; i < str.length(); ++i)
		if (str[i - 1] == 'A' && str[i] == 'C')
			return puts("Yes"), 0;
	return puts("No"), 0;
}