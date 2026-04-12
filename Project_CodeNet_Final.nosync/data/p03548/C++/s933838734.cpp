#include <bits/stdc++.h>
using namespace std;
 
int c, o, y, people;
 
int main () {
	cin >> c >> o >> y;
	people = (c-y)/(o + y);
	cout << people << endl;
}