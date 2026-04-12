#include<iostream>
using namespace std;

int main(){
	int r, g, b; cin >> r >> g >> b;
	cout << (!((10 * g + b) % 4) ? "YES\n" : "NO\n");
	return 0;
}