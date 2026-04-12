#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int X, Y, Z;
	scanf("%d %d %d", &X, &Y, &Z);
	printf("%d\n", (X - Z) / (Y + Z));
	return 0;
}
