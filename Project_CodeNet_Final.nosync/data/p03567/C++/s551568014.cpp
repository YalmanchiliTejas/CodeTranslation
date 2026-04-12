#include <stdio.h>
#include <string.h>

int main(void) {

    char str[5];

    scanf("%s", str);

    if (strstr(str, "AC"))
	printf("Yes\n");
    else
	printf("No\n");
    return 0;
}