#include<bits/stdc++.h>
#define FOR(i,j,k)  for(int i=(j);i<=(k);i++)
using namespace std;
int ans;
int main()
{
	int tmp;
	scanf("%d",&tmp);
	ans=tmp;
	scanf("%d",&tmp);
	ans*=10;
	ans+=tmp;
	scanf("%d",&tmp);
	ans*=10;
	ans+=tmp;
	if(ans%4==0)	printf("YES\n");
	else	printf("NO\n");
	return 0;
}
