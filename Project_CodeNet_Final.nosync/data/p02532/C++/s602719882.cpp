#include <stdio.h>
#include <string.h>

int main(void) {
	char i, cmd[5],color, mt[100][1000], pop[1000];
	int n, buf, buf2, popc = 0, mtc[100] = {0};
	
	scanf("%d",&n);
	
	while(scanf("%s",cmd)){
		if(!strcmp(cmd, "quit")) break;
		if(!strcmp(cmd, "push")) {
			scanf("%d",&buf);
			getchar();
			scanf("%c",&color);
			mt[buf-1][mtc[buf-1]] = color;
			mtc[buf-1]++;
			getchar();
		}
		else if(!strcmp(cmd, "pop")){
			scanf("%d",&buf);
			pop[popc] = mt[buf-1][mtc[buf-1]-1];
			mtc[buf-1]--;
			popc++;
		}
		else if(!strcmp(cmd, "move")){
			scanf("%d%d", &buf, &buf2);
			mt[buf2-1][mtc[buf2-1]] = mt[buf-1][mtc[buf-1]-1];
			mtc[buf2-1]++;
			mtc[buf-1]--;
		}
	}
	for(i = 0; popc > i; i++){
		printf("%c\n", pop[i]);
	}
	return 0;
}