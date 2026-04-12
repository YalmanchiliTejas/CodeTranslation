#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, cb, kembali, awal, diskon, total;
	cin >> n;
	awal = n*800;
	kembali = n/15;
	diskon = kembali*200;
	total = awal-diskon;
	cout << total << endl;
}