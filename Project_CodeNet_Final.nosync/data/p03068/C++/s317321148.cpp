#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int n;
	cin >> n;
	string a;
	cin >> a;
	a=' '+a;
	int k;
	cin >> k;
	for(int i=1;i<=n;i++)
		if(a[i]!=a[k]) a[i]='*';
	cout << a.substr(1); 
	return 0;
}