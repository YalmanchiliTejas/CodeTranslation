#include <iostream>

using namespace std;

int main()
{
	int r,g,b;
	cin >> r >> g >> b;
	int number;
	number = 100*r + 10*g + b;
	if (number%4==0){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
	return 0;
}