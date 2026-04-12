#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int s=b*10+c;
	if (s%4==0)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}