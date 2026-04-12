#include<iostream>
using namespace std;
char n;
int main()
{
	while(cin>>n)
	{
		if(n=='A')
		{
			cin>>n;
			if(n=='C')
			{
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}