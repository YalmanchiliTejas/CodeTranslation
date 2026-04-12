#include <iostream>
#include <algorithm>

using namespace std;


int main() {
	
	int L[12];
	int c[3] = { 0,0,0 };

	for (int i = 0; i < 12; i++)
		cin >> L[i];

	sort(L, L + 12);

	for (int i = 0; i < 3; i++) {
		if (L[0] == L[i + 1])
			c[0]++;
		if (L[4] == L[i + 5])
			c[1]++;
		if (L[8] == L[i + 9])
			c[2]++;
	}

	if (c[0] == 3 && c[0] == c[1] && c[1] == c[2])
		cout << "yes\n";

	else
		cout << "no\n";

	return 0;

}





