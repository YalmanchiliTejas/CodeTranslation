#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n,k;
	string s;
	cin >> n;
	cin >> s;
	cin >> k;
	char key = s[k-1];
	for (int i=0; i < n; i++) {
		if ( s[i] != key ) {
			s.replace(i,1,"*");
		}
	}
	cout << s;
	return 0;
}

