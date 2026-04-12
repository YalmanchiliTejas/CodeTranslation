#include<bits/stdc++.h>
using namespace std;
long long k,s=1,sum=0,ans=0,n,i,j;
char a[10000001];
int main()
{
    scanf("%s",a);
    for(i=0;i<=strlen(a)-1;i++)
    {
    	if(a[i]=='A'&&a[i+1]=='C')
    	{
    		cout<<"Yes";
    		return 0;
		}
	}
	cout<<"No";
	return 0;
} 