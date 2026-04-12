#include <iostream>
#define p cout << "?";
#define tie ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int main()
{
	char a[10];
	cin>>a;
	for(int i=0;a[i+1]!='\0';i++)
	{
		if(a[i]=='A'&&a[i+1]=='C')
		{
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}
