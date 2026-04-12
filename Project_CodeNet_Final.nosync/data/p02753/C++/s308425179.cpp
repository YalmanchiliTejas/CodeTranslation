#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int s1=0,s2=0;
	
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]=='A')
			s1++;
		else if(s[i]=='B')
			s2++;
	}
	
	if(s1>=1 && s2>=1)
		cout<<"Yes"<< endl;
	else
		cout<<"No"<< endl;
	
	return 0;
}