#include <bits/stdc++.h>

using namespace std;

int main( ) {
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t,n;
	t = 1;
	while(t--) {
	 cin >> n;
	 cout << (n * 800) - 200 * (n / 15) << endl;
	}
	return 0;
}

