#include <iostream>
using namespace std;

int main()
{
	int n,k;
	string s;
	char resident;
	cin  >> n >> s >> k;
	resident = s[k-1];
	for (int i = 0; i < n; i++) {
		if (s[i] != resident) {
			s[i] = '*';
		}
	}

	cout << s << endl;

	return 0;
}