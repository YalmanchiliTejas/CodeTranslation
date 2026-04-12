#include <stdio.h>

int main()
{
	int n,k;
	char c[11];
	scanf("%d",&n);
	scanf("%s",&c);
	scanf("%d",&k);
	for(int i = 0;i < n;i++){
		if(c[i] != c[k - 1]) printf("*");
		else printf("%c",c[i]);
	}
	return 0;
}