#include <stdio.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	int count = 0;
	int max = 0;
	for (int i = 0; i < n; i++) {
		int h;
		scanf("%d",&h);
		if (h >= max) {
			max = h;
			count++;
		}
	}
	
	printf("%d",count);
	return 0;
}