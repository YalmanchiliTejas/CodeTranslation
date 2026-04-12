#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int l=s.length();
	for(int i=0;i<l-1;i++)
	{
		if(s[i]=='A'&&s[i+1]=='C')
		{
			printf("Yes\n");
            return 0;
		}
	}
    printf("No\n");
}
 