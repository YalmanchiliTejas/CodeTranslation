#include <iostream>
using namespace std;
int main ()
{
	char a,b,c;
	while (cin >>a>>b>>c)
	{
		int sum=0;
		
		if (a=='A')
		sum++;
		else
		sum--;
		
		if (b=='A')
		sum++;
		else
		sum--;
		
		if (c=='A')
		sum++;
		else
		sum--;
		
		if (sum==3)
		cout <<"No"<<endl;
		else if (sum==-3)
		cout <<"No"<<endl;
		else
		cout <<"Yes"<<endl;
	}
	return 0;
}