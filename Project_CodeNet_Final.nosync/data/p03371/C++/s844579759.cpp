#include <bits/stdc++.h>
using namespace std;

int main()
{

	int a,b,c,x,y;
	int price=0;
	cin >> a >> b >> c >> x >> y;

	int ab=min(x,y);
	if ((a+b)<c*2)
	{
		price+=(a+b)*ab;
	}
	else
	{
		price+=c*2*ab;
	}
	x-=ab;
	y-=ab;

	if (a<c*2)
	{
		price+=a*x;
	}
	else
	{
		price+=c*2*x;
	}

	if (b<c*2)
	{
		price+=b*y;
	}
	else
	{
		price+=c*2*y;
	}
	cout << price << endl;
}




