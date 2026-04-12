//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

#define MAX -210000000
#define MIN 210000000

int main(){
	
	int a,b,c[4],d[4],e,f;
	
	scanf("%d %d",&a,&b);
	
	while(a!=0 && b!=0){
		for(int i=1;i<5;i++) scanf("%d %d",&c[i],&d[i]);
		
		e=a+b;
		f=0;
		
		for(int i=1;i<5;i++){
			if(e<c[i]+d[i]){
				e=c[i]+d[i];
				f=i;
			}
		}
		
		if(f==0){
			printf("A %d\n",e);
		}else if(f==1){
			printf("B %d\n",e);
		}else if(f==2){
			printf("C %d\n",e);
		}else if(f==3){
			printf("D %d\n",e);
		}else if(f==4){
			printf("E %d\n",e);
		}
		scanf("%d %d",&a,&b);
	}
	return 0;
}