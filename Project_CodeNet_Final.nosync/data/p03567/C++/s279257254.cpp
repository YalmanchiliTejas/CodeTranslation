#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 50;
char a[maxn];
int main()
{
	cin>>a;
	for(int i = 0; i < strlen(a); i++)
	{
		if(a[i] == 'A' && a[i+1] == 'C')
		{
			printf("Yes");
			return 0;
		}
	}
	printf("No");
	return 0;
}