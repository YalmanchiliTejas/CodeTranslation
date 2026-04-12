#include <stdio.h>

using namespace std;

int X;

int main()
{
	scanf("%d", &X);

	if (X == 3 || X == 5 || X == 7) printf("YES");
	else printf("NO");
}