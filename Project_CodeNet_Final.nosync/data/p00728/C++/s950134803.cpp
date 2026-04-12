#include <stdio.h>

int max = 0;
int min = 1000;

int maximum(int s)
{
	if(max < s){ max = s; }
	
	return max;
}


int minimum(int s)
{
	if(min > s){ min = s; }
	
	return min;
}


int main(void)
{
	int n;
	int i;
	int s;
	
	while(scanf("%d", &n) != EOF){
		if(n == 0){ break; }
		int ans = 0;
		int maxi, mini;
		for(i = 0; i < n; i++){
			scanf("%d", &s);
			maxi = maximum(s);
			mini = minimum(s);
			ans += s;		
		}
		ans = (ans - maxi - mini) / (n - 2);
		printf("%d\n", ans);
		
		max = 0;
		min = 1000;
	}
	return 0;
}