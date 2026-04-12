#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#ifndef U_L_LONG
typedef unsigned long long U_L_LONG;
#endif
#ifndef L_LONG
typedef long long L_LONG;
#endif


static void B_eeee();

int main()
{
	B_eeee();
	
	fflush(stdout);
	return 0;
}

static void B_eeee()
{
	int N = 0, K = 0;
	char szS[16] = { 0 };

	scanf(" %d %s %d", &N, szS, &K);

	char target = szS[K - 1];

	for (int i = 0; i < N; i++) {
		if (szS[i] != target) {
			szS[i] = '*';
		}
	}

	printf("%s\n", szS);

}
