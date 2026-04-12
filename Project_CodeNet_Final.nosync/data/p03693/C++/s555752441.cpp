#include <bits/stdc++.h>
using namespace std;
int main () {
	int a,b,c;
	cin >> a >> b >> c;
	if((10 * b + c) % 4 == 0){
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
}