#include<cstdio>
#include<iostream>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int X, Y, Z;

int main(){
	while(scanf("%d %d %d", &X, &Y, &Z) != EOF)
	{
		printf("%d\n", (X - Z) / (Z + Y));
	}
	return 0;
}