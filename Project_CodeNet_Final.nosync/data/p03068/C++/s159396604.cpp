#include <iostream>
#include<string>

using namespace std;

int main() {
	int k, n;
	string s,check,z;
	cin >> n >> s >> k;
	check = s[k-1];
	for (int i = 0; i < n; i++) {
		if (check[0] != s[i]) {
			z = "*";
			s[i] = z[0];
		}
	}
	cout << s << endl;
	
	return 0;
}