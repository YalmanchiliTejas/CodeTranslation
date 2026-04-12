#include <stdio.h>

int main(){

	int r, g, b;

	scanf("%d", &r);
	if(r >= 10 || r <= 0) return 0;
	
	scanf("%d", &g);
	if(g >= 10 || g <= 0) return 0;

	scanf("%d", &b);
	if(b >= 10 || b <= 0) return 0;


	if((r*100 + g*10 + b) % 4 == 0) printf("\nYES\n");
	else printf("\nNO\n");

  return 0;
}