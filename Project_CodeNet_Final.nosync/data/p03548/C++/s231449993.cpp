#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	int t,x,y,z;
	scanf("%d %d %d",&x,&y,&z);
	if(y+2*z<=x){
		t=(x-z)/(y+z);
		printf("%d\n",t);
	}
}