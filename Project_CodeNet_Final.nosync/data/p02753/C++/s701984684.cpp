#include <stdio.h>
#include <string.h>
int main(void) {
	char arr[3];
	scanf("%s", arr);
	if(strcmp(arr, "AAA")==0 || strcmp(arr, "BBB")==0)
		printf("No");
	else
		printf("Yes");
	return 0;
}