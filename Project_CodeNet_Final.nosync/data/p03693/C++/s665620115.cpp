#include <iostream>
using namespace std;

int main() {
	int r, g, b;
	int num = 0;

	cin >> r >> g >> b;

	num = g * 10 + b;

	if((num % 4) == 0){
		cout << "YES";
	}
	else{
		cout << "NO";
	}

}
