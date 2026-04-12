#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

char a[10];
int main()
{
	scanf("%s", a);
	int len = strlen(a);
	for(int i = 0; i <= len - 1; i++)
	{
		if(a[i] == 'A' && a[i + 1] == 'C') {
			printf("Yes\n");
			break;
		}
		if(i == len - 1) printf("No\n");
	}
	return 0;
}