#include <bits/stdc++.h>
using namespace std;
int main() {
	char c[3];
  	cin >> c[0] >> c[1] >> c[2];
  	bool w = 0;
  	w |= c[0] == 'A' && c[1] == 'B';
  	w |= c[1] == 'A' && c[0] == 'B';
	w |= c[1] == 'A' && c[2] == 'B';
  	w |= c[2] == 'A' && c[1] == 'B';
  	cout << (w ? "Yes" : "No") << endl;

}