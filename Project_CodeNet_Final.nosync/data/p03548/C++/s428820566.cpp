#include <cstdio>

int x, y, z;

int main(){
	scanf("%d %d %d", &x, &y, &z);
	printf("%d\n", (x-z)/(y+z));
}