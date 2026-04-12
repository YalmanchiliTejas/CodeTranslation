#include <stdio.h>
int main(void){
	int count = 0, n, h[100] = {0};
	scanf("%d", &n);getchar();
	for(int i = 0; i < n; i++){
		scanf("%d", &h[i]);getchar();
	}
	for(int i = 0; i < n; i++){
		int lookable = 1;
		for(int j = 0; j < i; j++){
			if(h[j] > h[i]){
				lookable = 0;
			}
		}
		if(lookable){
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}