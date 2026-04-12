#include<bits/stdc++.h>
# define ll long long
# define mo 1000000009
using namespace std;
int main()
{
	string s;
	cin>>s;
	int a=0,b=0;
	for(int i=0;i<3;i++)
	{
		if(s[i]=='A')
		a++;
		else
		b++;
	}
	if(a==3||b==3)
	cout<<"No";
	else
	cout<<"Yes";
	return 0;
}