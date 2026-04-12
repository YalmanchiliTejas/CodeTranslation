#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	int ans=a*100+b*10+c;
	if (ans%4==0) printf("YES");
	else printf("NO");
	return 0;
}