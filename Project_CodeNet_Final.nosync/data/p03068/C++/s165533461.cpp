#include<stdio.h>
int main(void)
{
	int k,n,i;
	char s[100];
	scanf("%d", &k);
	scanf("%s", &s);
	scanf("%d", &n);
	for (i = 0; i < k; i++){
		if (s[n-1] != s[i])
			s[i] = '*';
	}
	printf("%s\n",s);
	return 0;
}