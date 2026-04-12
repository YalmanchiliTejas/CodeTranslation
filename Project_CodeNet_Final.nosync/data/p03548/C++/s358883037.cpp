#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
	int X, Y, Z;
	cin >> X >> Y >> Z;

	int answer = (X - Z) / (Y + Z);
	cout << answer << endl;	
	return 0;
}
