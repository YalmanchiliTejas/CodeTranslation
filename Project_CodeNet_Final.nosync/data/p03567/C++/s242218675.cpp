#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <iostream>

#pragma comment(linker, "/STACK:336777216")  

using namespace std;

const int MAXN = 400000 + 10;

char S[MAXN];

void Work()
{
	scanf("%s", S);
	for (int i = 0; S[i]; i ++)
		if (S[i] == 'A' && S[i + 1] == 'C')
		{
			printf("Yes\n");
			return;
		}
	printf("No\n");
}

int main()
{
	Work();
	return 0;
}