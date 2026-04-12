#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int main (){
	int X,Y,Z,num = 0;
	while(~scanf("%d%d%d",&X,&Y,&Z)){
		num = (X - Z) / (Y + Z);
		printf("%d\n",num);
	}
	return 0;
}
