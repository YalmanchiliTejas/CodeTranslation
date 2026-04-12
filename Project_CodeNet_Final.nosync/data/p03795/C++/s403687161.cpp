#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int x=n*800;
	int y=(n/15)*200;
	x-=y;
	printf("%d",x);
}