#define loop(i, n) for (int i = 0; i < n; i++)
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main() {
	bool a = false, b = false;
	for (int i = 0; i < 3; i++) {
		char temp;	cin >> temp;
		if (temp == 'A')	a = true;
		if (temp == 'B')	b = true;
	}
	if (a && b) 	cout << "Yes" << endl;
	else cout << "No" << endl;
	


	return 0;
}