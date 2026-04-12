#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[1001];
bool ok;
int main()
{
	scanf("%s",a+1);
	int len=strlen(a+1);
	for(int i=1;i<=len;i++)
	{
		if(a[i]=='A'){
			if(a[i+1]=='C'){
				ok=1;cout<<"Yes";break;
			}
		}
	}
	if(ok==0)cout<<"No";
	return 0;
 } 