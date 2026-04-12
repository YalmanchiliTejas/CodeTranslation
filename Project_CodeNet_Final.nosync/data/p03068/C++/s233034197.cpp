#include <string>
#include <algorithm>
#include <vector> 
#include <math.h>
#include <iostream>
using namespace std;
long long mod = 1000000000 + 7;



int main()
{
	int n,k;
	string s;
	cin >> n;
	cin >> s;
	cin >> k;

	char a = s[k - 1];

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != a) {
			s[i] = '*';
		}

	}
	
	cout << s << endl;
	return 0;

}