#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
int main ()
{
	int n;
	char s[10];
	scanf("%s",&s);
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == 'A')
		if (s[i+1] =='C') 
		{
			printf("Yes\n");
			return 0;
			}
		}
		printf("No\n");
	return 0;
	}