#include <bits/stdc++.h>
using namespace std;

int main(){
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	x -= z;
	y += z;
	printf("%d\n", x/y);
	return 0;
}