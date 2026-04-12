#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;

	int cntA=0,cntB=0;
	for(int i=0;i<3;i++)
	{
		if(s[i] == 'A')
			cntA++;
		if(s[i] == 'B')
			cntB++;
	}

	if(cntA && cntB)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}

	return 0;
}