#include <bits/stdc++.h>

using namespace std;

char a[10];
int ff;

int main(void)
{
	scanf("%s", a);
	
	if(a[0] == a[1] && a[1] == a[2])
		ff = 1;
	
	if(ff == 1)
		printf("No");
	else
		printf("Yes");
	
	return 0;
}