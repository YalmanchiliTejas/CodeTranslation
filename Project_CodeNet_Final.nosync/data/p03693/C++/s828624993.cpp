#include <iostream>
using namespace std;

int main(){
	int r,g,b,num;
	cin >> r >>g>>b;
	
	num = g * 10 + b;

	if (num % 4 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;

}