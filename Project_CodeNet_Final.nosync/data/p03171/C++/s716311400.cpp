#include<bits/stdc++.h>
using namespace std;
long long arr[3001];
pair<long long,long long>ar[3001][3001];
int main()
{
	long long n,i,j;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",arr+i);
		ar[i][i].first=arr[i];
		ar[i][i].second=0;
	}
	i=1,j=2;
	long long c=j;
	while(1)
	{
		if(j==n+1 && i==1)
			break;
		c=j;
		while(j!=n+1)
		{
			if(ar[i][j-1].second+arr[j] > ar[i+1][j].second+arr[i])
			{
				ar[i][j].first=ar[i][j-1].second+arr[j];
				ar[i][j].second=ar[i][j-1].first;
			}
			else
			{
				ar[i][j].first=ar[i+1][j].second+arr[i];
				ar[i][j].second=ar[i+1][j].first;
			}
			j++;
			i++;
		}
		i=1;
		c++;
		j=c;
	}
	/*for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%lld,%lld ",ar[i][j].first,ar[i][j].second);
		printf("\n");
	}*/
	printf("%lld\n",ar[1][n].first-ar[1][n].second);
}
