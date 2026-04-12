#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N,x,y,cnt;
	scanf("%d",&N);
	x = N * 800;
	cnt = N / 15;
	y = cnt * 200;
	printf("%d\n",x - y);
	return 0;
}
