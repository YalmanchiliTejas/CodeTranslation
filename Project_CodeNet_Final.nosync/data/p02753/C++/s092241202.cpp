#include<stdio.h>

int main()
{
	char s[3]={NULL};
	int cnt_a=0, cnt_b=0;
	scanf("%s", s);

	for(int i=0; i<3; i++){
		if (s[i]=='A') cnt_a++;
		else cnt_b++;
	}

	if (cnt_a == 0 || cnt_b ==0) printf("No\n");
	else printf("Yes\n");

	return 0;
}