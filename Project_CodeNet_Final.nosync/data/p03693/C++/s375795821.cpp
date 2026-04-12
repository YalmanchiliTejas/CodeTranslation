#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int i,j,n,a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if((a*100+b*10+c)%4==0){
		printf("YES");
	}else{
		printf("NO");
	}
	return 0;
}