#include<bits/stdc++.h>
using namespace std;
int n,a[51][200];
char s[51];
int main()
{
	int len;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
	  scanf("%s",s);
	  len=strlen(s);
	  for (int j=0;j<len;j++)
	    a[i][s[j]]++;
    }
    int min1;
    for (int i='a';i<='z';i++)
    {
    	min1=5005;
    	for (int j=1;j<=n;j++)
    	  min1=min(min1,a[j][i]);
    	for (int j=1;j<=min1;j++)
    	  printf("%c",i);
	}
	return 0;
}