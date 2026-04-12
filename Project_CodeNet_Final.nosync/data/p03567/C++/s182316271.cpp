#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	cin>>a;
	int i;
	int lt=0;
	for(i=0;i<(int)a.size()-1;i++)
		if(a[i]=='A'&&a[i+1]=='C')
		{
			lt=1;
			break;
		}
	if(lt)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}