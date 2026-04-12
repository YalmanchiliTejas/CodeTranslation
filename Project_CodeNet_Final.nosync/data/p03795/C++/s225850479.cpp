#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,sum=0,dis=0,pay=0;
	scanf("%d",&n);
	sum=n*800;
	dis=(n/15)*200;
	pay=sum-dis;
	printf("%d",pay);
    return 0;
}