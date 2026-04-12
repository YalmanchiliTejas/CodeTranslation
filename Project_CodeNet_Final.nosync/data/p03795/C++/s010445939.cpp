#include<iostream>
using namespace std;

int main() {
	int a, potongan ,harga, jadinya, cashback;
	cin >> a;
	potongan = a / 15;
	cashback = potongan * 200;
	harga = a* 800;
	jadinya = harga - cashback;
	cout << jadinya << endl;
	return 0;
}