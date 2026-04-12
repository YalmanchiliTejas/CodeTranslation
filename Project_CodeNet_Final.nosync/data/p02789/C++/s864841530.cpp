#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
int a[3];
int n;

for (n = 1; n <= 2; n++){
	scanf("%d",&a[n]);
}

if (a[1] == a[2]) printf("Yes");
else printf("No");

return 0;
}

