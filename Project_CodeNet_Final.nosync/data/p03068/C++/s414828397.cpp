#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int n, k;
string s;
char x;

int main(){

	cin >> n >> s >> k;

	x = s[k - 1];

	for (int i = 0; i < n; i++){
		if (x != s[i]) s[i] = '*';
	}

	cout << s << endl;

	return 0;
}