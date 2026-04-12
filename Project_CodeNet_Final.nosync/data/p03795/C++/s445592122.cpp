#include <iostream>

using namespace std;

int main(){
	int n = 0;
	cin >> n;
	int y = (n - n%15)/15;
	cout << 800*n - 200*y << endl;

	return 0;
}