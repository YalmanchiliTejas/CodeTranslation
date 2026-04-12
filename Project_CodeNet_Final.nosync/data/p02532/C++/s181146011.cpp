#include <stdio.h>
#include <string.h>

int main(void)
{
	char stack[108][1005];
	int sp[108];
	int n;

	memset(sp, 0, sizeof(sp));

	scanf("%d", &n);
	while (1){
		char str[100];
		int p;

		scanf("%s", str);

		if (strcmp(str, "push") == 0){
			char c[2];
			scanf("%d%s", &p, c);
			stack[p][sp[p]++] = c[0];
		}
		else if (strcmp(str, "pop") == 0){
			scanf("%d", &p);
			printf("%c\n", stack[p][--sp[p]]);
		}
		else if (strcmp(str, "move") == 0){
			int to, from;
			int value;
			scanf("%d%d", &from, &to);
			value = stack[from][--sp[from]];
			stack[to][sp[to]++] = value;
		}
		else if (strcmp(str, "quit") == 0){
			break;
		}
	}

	return (0);
}