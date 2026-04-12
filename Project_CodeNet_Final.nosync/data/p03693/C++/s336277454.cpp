#include <iostream>
using namespace std;

int main(){
	int r, g, b;
	cin >> r >> g >> b;
	int judge = g * 10 + b;
	if (judge % 4 == 0) {
		cout << "YES";
	}else {
		cout << "NO";
	}
}