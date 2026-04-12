#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int x,y,z,n;
	while(~scanf("%d%d%d",&x,&y,&z)){
	n=(x-z)/(y+z);
	printf("%d\n",n);
	}
}
