#include <bits/stdc++.h>
using namespace std;

int main() {
	int X,Y,Z,r;
	cin >> X >> Y >> Z;

	r = X/(Y+Z);
	if(X-r*(Y+Z) < Z)
		--r;
	cout << r << endl;
}