
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

//typedefリスト
typedef vector<int> vint;
typedef vector<string> vstr;

int main(void) {
	string s;
	int size,a;
	a = 0;
	cin >> s;
	size = s.length();
	for (int i = 1; i < size; i++) {
		if (s[i - 1] == 'A'&&s[i] == 'C')a = 1;
	}
	if(a==1)cout << "Yes" << endl;
		else cout << "No" << endl;
}
