#include <iostream>
using namespace std;

int main()
{
	int n,ans,tot;
	cin >> n;
	
	ans=n/15;
	ans=ans*200;
	tot=n*800;
	cout << tot-ans << endl;
	return 0;	
}
