#include<bits/stdc++.h>
#define lld long long 
#define pb push_back
#define mk make_pair
using namespace std;

int main()
{
	
	string s;
	cin>>s;

	int a=0,b=0;

	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='A')
			a++;

		else
			b++;
	}

	if(a==2 || b==2)
		cout<<"Yes"<<"\n";
	else
		cout<<"No"<<"\n";
	
}