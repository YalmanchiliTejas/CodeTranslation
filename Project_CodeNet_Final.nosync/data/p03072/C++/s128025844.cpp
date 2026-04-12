#include <stdio.h> 
#include <algorithm>
int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	int ans = 0, N = 0, H[20] = {}, Hmax = -1;
	scanf("%d",&N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &H[i]);
		Hmax = max(Hmax, H[i]);
		if (Hmax == H[i])ans += 1;
	}
	printf("%d", ans);
	return 0;
}