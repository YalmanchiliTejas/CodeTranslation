#include <bits/stdc++.h>
using namespace std;

int main() {
	int r,g,b;
	cin >> r >> g >> b;
	string k = "NO";
	if((10 * g + b) % 4 == 0)
	{
		k = "YES";
	}
    cout << k << endl;
	return 0;
}
