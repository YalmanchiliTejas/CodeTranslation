#include<bits/stdc++.h>

using namespace std;
char a[105];
int ans,p;
int main()
{
	scanf("%s",a);
	int l=strlen(a);
	for(int i=0;i<l-1;i++)
		if(a[i]=='A'&&a[i+1]=='C')
		{
			cout<<"Yes\n";
			return 0;
		}
	cout<<"No"<<endl;
	return 0;
}
