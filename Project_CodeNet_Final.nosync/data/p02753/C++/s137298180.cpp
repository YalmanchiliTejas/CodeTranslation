#include<bits/stdc++.h>
using namespace std;
int s[100003];
char a[10];
int main()
{
	scanf("%s",a);
	for(int i=0;i<=2;i++)
		s[a[i]]++;
	if(s['A']!=0&&s['B']!=0)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}
