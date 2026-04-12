#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int l,flag;
	char a[10];
	while(~scanf("%s",a+1)){
		flag=0;
		l=strlen(a+1);
		for(int i=1;i<=l-1;i++){
			if(a[i]=='A'&&a[i+1]=='C') flag=1;
		}
		if(flag==1) printf("Yes\n");
		else printf("No\n");
	}
}