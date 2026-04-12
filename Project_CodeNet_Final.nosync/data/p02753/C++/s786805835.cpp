#include <bits/stdc++.h>
using namespace std;
char a[5];
int main()
{
	scanf("%s",a);
	if(a[0]!=a[1] || a[0]!=a[2] || a[1]!=a[2]) puts("Yes");
	else puts("No"); 
	return 0;
}