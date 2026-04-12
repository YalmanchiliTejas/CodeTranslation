#include<iostream>
using namespace std;

int main()
{
	string a;
	char i, b, n;

	cin >> a;

	i = a[0];
	b = a[1];
	n = a[2];

	
	if (i==b&&b==n){
		cout << "No";
	}
	else {
		cout << "Yes";
	}
	
	return 0;
}