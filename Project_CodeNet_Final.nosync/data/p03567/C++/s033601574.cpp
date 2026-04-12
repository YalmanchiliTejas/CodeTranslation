#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
char a[7];

int main()
{
	scanf("%s", a);
	int len = strlen(a);
	int flag = 0;
	for (int i = 0; i < len; i++){
		if (a[i] == 'A'){
			if (a[i + 1] == 'C'){
				printf("Yes\n");
				flag = 1;
				break;
			}
		}
	}
	if (!flag)
		printf("No\n");

	return 0;
}