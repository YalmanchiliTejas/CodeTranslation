#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[100];
	cin>>n;
	int s=0,g=0;
	while(n--)
	{
		int d;
		cin>>d;
		g=max(d,g);
		if(d>=g) s++;
	}
	printf("%d",s);
}