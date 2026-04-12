#include <stdio.h>
#include <algorithm>

int main(void)
{
	int data[101];
	int n;
	int sum;
	
	while (1){
		scanf("%d", &n);
		if (n == 0){
			break;
		}
		for (int i = 0; i < n; i++){
			scanf("%d", data + i);
		}
		std::sort(data, data + n);
		sum = 0;
		for (int i = 1; i < n - 1; i++){
			sum += data[i];
		}
		printf("%d\n", sum / (n - 2));
	}
	return (0);
}