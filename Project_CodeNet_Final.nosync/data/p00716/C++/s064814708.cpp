#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int a;
	scanf("%d",&a);
	while(a--){
		int b;
		int c,d;
		scanf("%d%d%d",&b,&c,&d);
		int ret=0;
		for(int i=0;i<d;i++){
			int e;
			double f;
			int g;
			scanf("%d%lf%d",&e,&f,&g);
			if(!e){
				int h=b;
				int v=0;
				for(int j=0;j<c;j++){
					v+=f*h;
					h-=g;
				}
				ret=max(ret,h+v);
			}else{
				int h=b;
				for(int j=0;j<c;j++){
					h=h+f*h-g;
				}
				ret=max(ret,h);
			}
		}
		printf("%d\n",ret);
	}
}