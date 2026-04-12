#include "bits/stdc++.h"
using namespace std;
 int main() {
string s; cin >> s;
char a = s.at(0);
char b = s.at(1);
char c = s.at(2);
if (a==b && b ==c) {
	cout << "No\n";
}
else {
	cout << "Yes\n";
}
}