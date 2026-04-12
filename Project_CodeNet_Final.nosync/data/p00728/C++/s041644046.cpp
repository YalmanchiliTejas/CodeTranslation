#include <stdio.h>
int main() {
    for(int x=0;x<1000;x++){
	int a = 0;
	scanf("%d", &a);
	int g[1000] = {};
	for (int i = 0; i < a; i++) {
		scanf("%d", &g[i]);
	}
	int sd = 0;
	int ss = 0;

	sd = g[1];
	ss = g[1];
	for (int i = 0; i < a; i++) {
		if (g[i] > sd) {
			sd = g[i];
		}
		if (g[i] < ss) {
			ss = g[i];
		}
	}
	int g1 = 0;
	for (int i = 0; i < a; i++) {
		g1 = g1 + g[i];
	}
	int g2 = 0;
	g2 = g1 - sd - ss;
	a = a - 2;
	g2 = g2 / a;
	if(g2==0){
	    
	}else {
	printf("%d\n", g2);
	}
}
return 0;
}
