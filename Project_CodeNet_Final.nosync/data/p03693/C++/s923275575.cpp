#include <iostream>
using namespace std;
main () {
	int r, g, b, result;
	cin>>r>>g>>b;
	result = (r*100) + (g*10) + b;
	if (result % 4 == 0)
	{
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
}