#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<iostream>

using  namespace std;


int main(){
	int n,h,y;	
	scanf("%d",&n);
	if(n>=15){
		h=n/15*200;
		y=n*800-h;
		}
		else if(n<15){
			y=n*800;
			}
			printf("%d\n",y);
			return 0;
		}