#include <stdio.h>

#define STR_LENGTH (3)
int main(int argc, char* argv[])
{
	//ABC158 A
	int i;
	char param;
	char s[STR_LENGTH + 1];
	int isDiff = 0;

	scanf("%s", &s[0]);

	param = s[0];
	for (i = 1; i < STR_LENGTH; i++) {
		if (param != s[i]) {
			isDiff = 1;
		}
		
	}

	if (isDiff == 1) {
		printf("Yes");
	}
	else {
		printf("No");
	}

	return 0;
}

