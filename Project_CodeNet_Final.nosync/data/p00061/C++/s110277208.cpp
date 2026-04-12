#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int x[10000],y[10000],a,s,i=0,j,sum=0,z[10000]={};
	while(1){
		scanf("%d,%d",&s,&a);
		if(s==0) break;
		x[s-1]=a;
		y[s-1]=x[s-1];
		sum++;
	}
	sort(x,x+sum);
	int r=100;
	for(i=0;i<sum;i++){
		for(j=0;j<sum;j++){
		if(x[i]<x[j]){
			if(r!=x[j]){
			z[i]++;
			r=x[j];
		}
		}} r=100;}
int d;
				while(scanf("%d",&d)!=EOF){
					for(i=0;i<sum;i++){
						if(x[i]==y[d-1]){
					printf("%d\n",z[i]+1);
					goto yu;
						}}yu:;
				}
				return 0;
}