#include <bits/stdc++.h>
using namespace std;
string sa; 
int a,b;
int main()
{
	cin>>sa;
	for(int i=0;i<sa.size();i++)
	{
		if(sa[i]=='A')
			a++;
		else
			b++;
	}
	if(a && b)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}
