#include<bits/stdc++.h>
using namespace std;
int main()
{
	int flag=0,i;
	char a[3];
	cin>>a;
	for(i=0;i<3;i++)
		if(a[i]=='A')
			flag++;
	if(flag==0||flag==3)
		printf("No\n");
	else
		printf("Yes\n");
}