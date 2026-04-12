#include <bits/stdc++.h>
using namespace std;
string str;
int n,k;
int main()
{
	scanf("%d",&n);
	cin>>str;
	scanf("%d",&k);
	for(int i=0;i<n;i++)
		if(str[i]==str[k-1])
			printf("%c",str[i]);
		else printf("*");
	return 0;
}