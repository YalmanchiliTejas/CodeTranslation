#include<iostream>
#include<stdio.h>
using namespace std;

int main(void) {
	int X;
	scanf("%d", &X);
	printf(X == 3 || X == 5 || X == 7 ? "YES\n" : "NO\n");
	return 0;
}
