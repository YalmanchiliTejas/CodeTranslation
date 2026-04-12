#include<iostream>
using namespace std;
int main()
{
	char a,b,c;
	while(cin>>a>>b>>c)
	{
		if(a=='A' && b=='A' && c=='A')
		cout<<"No";
		else if(a=='B' && b=='B' && c=='B')
		cout<<"No";
		else
		cout<<"Yes";
		cout<<endl;
	}
	return 0;
}
