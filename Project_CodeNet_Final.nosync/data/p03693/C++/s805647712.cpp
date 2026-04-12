#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int a, b, c;
int main()
{
	while(scanf("%d %d %d", &a, &b, &c) != EOF)
	{
		int x = a * 100 + b * 10 + c;
		if(x % 4 == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}