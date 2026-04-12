#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int X,Y,Z;
	scanf(" %d %d %d", &X, &Y, &Z);
	printf("%d\n",(X - Z) / (Z + Y));
	return 0;
}