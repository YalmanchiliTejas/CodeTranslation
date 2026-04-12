#include <bits/stdc++.h>
using namespace std;

int n, harga, diskon, total;

int main () {
	cin >> n;
	harga = n * 800;
	if (n>15){
		diskon = n/15 * 200;
	}
	total = harga - diskon;
	cout << total << endl;
}