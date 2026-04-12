#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int main(){
	int x,y,z,sum,flag;
	while(~scanf("%d%d%d",&x,&y,&z)){
		sum=0;
		flag=0;
		for(int i=1; ;i++){
			sum = sum+z;
			if(sum>=x) break;
			sum = sum+y;
			if(sum>x-z) break;
			flag++;
		}
		printf("%d\n",flag);
	}
}