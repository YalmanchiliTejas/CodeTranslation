#include <iostream>
using namespace std;


int main()
{
	int n,k;
	cin >> n;
	char s[11];
	
	cin >> s;
	cin >> k;

	char key = s[k-1];

	for (int i = 0; i < n; i++) {
		if (s[i] != key) {
			s[i] = '*';
		}
		
	}
	cout << s << endl;
	return 0;
}