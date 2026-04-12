#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int a,b,c,xa,yb;

	cin>>a>>b>>c>>xa>>yb;

	int cost1 = xa*a + yb*b;

	int cost2;
	int cost3;

	if(xa>yb)
	{
		cost2 = c*(2*yb) + (xa-yb)*a; 
	}
	else if(yb>xa)
	{
		cost2 = c*(2*xa) + (yb-xa)*b;
	}
	else if(xa==yb)
	{
		cost2 = c*(2*xa);
	}

	cost3 = max(yb,xa)*(2*c);

	cout<<min(cost1,min(cost2,cost3))<<'\n';
	return 0;	
}