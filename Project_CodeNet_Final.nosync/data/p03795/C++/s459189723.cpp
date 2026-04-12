#include <bits/stdc++.h>
using namespace std;
int main()
 
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n,x,total;
	cin>> n;
	if(n>15)
	{
       x=n/15;
       total=n*800;
       cout<<total-x*200<<"\n";

	}
	else
	{
		cout<<n*800<<"\n";
	}
}