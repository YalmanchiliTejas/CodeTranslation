#include <iostream>
using namespace std;

int main (){
	int x, y, a, n;
	cin >> n;
	
	x = 800*n;
	y = n/15*200;
	
	a = x-y;
	
	cout << a << endl;
	
	return 0;
}