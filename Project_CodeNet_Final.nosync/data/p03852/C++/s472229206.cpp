

#include <iostream>
#include <string>
#include<algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;
int main()
{
	int x = 1;
	string yn[2] = { "vowel","consonant" };
	char c;
	char v[5] = { 'a','i','u','e','o' };
	cin >> c;
	for (int i = 0; i < 5; i++) {
		if (c == v[i]) x = 0;
	}
	cout << yn[x] << endl;
	return 0;
}