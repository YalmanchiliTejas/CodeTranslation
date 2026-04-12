#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s[3];
	for(int i=1;i<=3;i++)
	  cin>>s[i];
	
	if(s[1]==s[2]&&s[1]==s[3])
	{
		cout<<"No";
		return 0;
	}
	
    cout<<"Yes";
    return 0;
}