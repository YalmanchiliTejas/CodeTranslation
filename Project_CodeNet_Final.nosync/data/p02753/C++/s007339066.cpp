#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	int i,counter;
	cin>>S;
	counter=0;
	for(i=1 ; i<3 ; i++)
	{
		if(S[i]!=S[0])
		{
			counter=1;
			break;
		}
	}
	if(counter==0)
	{
		cout<<"No";
	}
	else 
	{
		cout<<"Yes";
	}
	return 0;
}
