#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int a, b, c;
	cin >> a >> b >> c;
	if ((a*100 + b*10 + c) % 4) {cout << "NO";} else {cout << "YES";}

	return 0;
}