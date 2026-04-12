#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n, y, m;
  	y = 0;
  	scanf("%d", &n);
  	m = n;
  	while (n >= 0) {
      n = n - 15;
      if (n >= 0) {
        y = y + 200;
      }
    }
  	printf("%d", (800 * m) - y);
  	return 0;
}

