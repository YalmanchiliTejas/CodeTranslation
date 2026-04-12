#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);

	int x, n = 0;
	for (int i = 0; i < 3; i++){
		cin >> x;
		n = n*10 + x;
	}
	cout << (n % 4 ? "NO" : "YES");
	return 0;
}