#include <stdio.h>

int main(void)
{
	char inst[10];
	int n;
	int t;
	int ans;
	
	while (1){
		int dice[6] = {1, 2, 6, 5, 3, 4};
		
		scanf("%d", &n);
		if (!n)break;
		
		ans = 1;
		for (int i = 0; i < n; i++){
			scanf("%s", inst);
			
			switch (inst[0]){
			  case 'N':
			  	t = dice[0];
				dice[0] = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[3];
				dice[3] = t;
				break;
			  case 'E':
			  	t = dice[0];
				dice[0] = dice[5];
				dice[5] = dice[2];
				dice[2] = dice[4];
				dice[4] = t;
				break;
			  case 'W':
			  	t = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[2];
				dice[2] = dice[5];
				dice[5] = t;
				break;
			  case 'S':
			  	t = dice[0];
				dice[0] = dice[3];
				dice[3] = dice[2];
				dice[2] = dice[1];
				dice[1] = t;
				break;
				
			  case 'R':
			  	t = dice[1];
				dice[1] = dice[4];
				dice[4] = dice[3];
				dice[3] = dice[5];
				dice[5] = t;
				break;
				
			  case 'L':
			  	t = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[3];
				dice[3] = dice[4];
				dice[4] = t;
			  break;
			}
			ans += dice[0];
		}
		
		printf("%d\n", ans);
	}
	
	return (0);
}