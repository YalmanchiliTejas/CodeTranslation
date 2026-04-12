#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,d,e,g,i,j,k,f,t;
int A,B,C,X,Y,Z;
long long MIN ,ans,mid;
char str[3];

int main()
{
	a=0;
	b=0;
	scanf("%s",str);
	for(i=0;i<3;i++)
	{
		if(str[i]=='A') a=1;
		if(str[i]=='B') b=1;
	}
	if(a==1&&b==1) printf("Yes\n");
	else printf("No\n");
    return 0;
}