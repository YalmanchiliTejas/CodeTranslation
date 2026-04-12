#include <stdio.h>

int main(void)
{
	int n, t, e;
	int x[100];
	int i;
	int ans;
	int time;
	
	scanf("%d %d %d", &n, &t, &e);
	
	for (i = 0; i < n; i++){
		scanf("%d", &x[i]);
	}
	
	ans = -1;
	time = t - e;
	while (time <= t + e){
		for (i = 0; i < n; i++){
			if (time % x[i] == 0){
				ans = i + 1;
				break;
			}
		}
		time++;
	}
	printf("%d\n", ans);
	
	return (0);
}