#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	char s[3];
	scanf(" %s",s);
	ll a=0,b=0;
	for(ll i=0;i<3;i++)
	{
		if(s[i]=='A')
		{
			a++;
		}
		else
		{
			b++;
		}
	}
	if(a*b==0)
	{
		printf("No\n");
	}
	else
	{
		printf("Yes\n");
	}
 }