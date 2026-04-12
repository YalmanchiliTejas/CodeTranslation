#include <bits/stdc++.h>

using namespace std;

int main() {

	string r,g,b;
	cin >> r >> g >> b;

	long n;
	n = (stol(r) * 100 + stol(g) * 10 + stol(b)) % 4;

	cout <<  (n==0? "YES" : "NO") << endl;
}