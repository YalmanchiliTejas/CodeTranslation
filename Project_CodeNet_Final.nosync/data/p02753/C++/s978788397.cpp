#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a=0,b=0,i=1;
	string x;
	cin>>x;
	for(i=0;i<3;i++)
	{
		if(x[i]=='A')
		a++;
		else
		b++;
	}
	if(a==3 || b==3)
	cout<<"No"<<endl;
	else
	cout<<"Yes"<<endl;
	return 0;
}