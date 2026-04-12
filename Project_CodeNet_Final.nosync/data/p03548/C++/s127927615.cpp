#include <bits/stdc++.h>
using namespace std;

int x, y, z, people;

int main () {
	cin >> x >> y >> z;
	people = (x-z)/(y + z);
	cout << people << endl;
}
