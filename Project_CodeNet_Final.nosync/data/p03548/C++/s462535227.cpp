#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	int x,y,z,j,sum;
	sum = j = 0;
	scanf("%d %d %d",&x,&y,&z);
	for(;;){
		sum = sum + z;
		sum = sum + y;
		j++;
		if(sum == x-z) { printf("%d\n",j);break;}
		else if(sum < x-z) {;}
			 else {printf("%d\n",j-1);break;}
	}
}