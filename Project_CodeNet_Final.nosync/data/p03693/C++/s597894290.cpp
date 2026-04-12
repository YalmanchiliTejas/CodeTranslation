#include <cstdio>
using namespace std;

int main()
{
	int r, g, b;
	scanf("%d %d %d", &r, &g, &b);
	if ((r * 100 + g * 10 + b) % 4) 
		printf("NO\n");
	else
		printf("YES\n");

	return 0;
}