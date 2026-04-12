#include<iostream>
using namespace std;

int main()
{
	int a,b;
	cin >> a >> b;
	//Not Using ternary operator
	//"if" sentence divergence
	if (a < b)		cout << "a < b" << endl;
	else if(a > b)	cout << "a > b" << endl;
	else			cout << "a == b" << endl;
}