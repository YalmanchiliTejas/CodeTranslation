#include <iostream>
using namespace std;

int a, b;

int main(){
	cin >> a >> b;
	if(a < b)
		cout << "a < b" << endl;
	if(a > b)
		cout << "a > b" << endl;
	if(a == b)
		cout << "a == b" << endl;
	return 0;
}