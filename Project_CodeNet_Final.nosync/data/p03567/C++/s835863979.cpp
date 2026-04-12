#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	string S;
	cin>>S;
	bool ok=false;
	for(int i=0;i<S.size();i++)
	{
		if(S[i]=='A'&&S[i+1]=='C')
			{ok=true;break;}
	}
	if(ok)
		puts("Yes");
	else
		puts("No");
	return 0;
}