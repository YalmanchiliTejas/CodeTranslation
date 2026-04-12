#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	bool MarkA=false,MarkB=false;
	for (int i=0;i<3;++i)
		if (s[i]=='A') MarkA=true;
		else MarkB=true;
	if (MarkA && MarkB) printf("Yes\n");
	else printf("No\n");
	return 0;
}