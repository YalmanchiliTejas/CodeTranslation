#include<stdio.h>

int main(){
	int i,j,m,s,y,n,f,k,maxs,ts,tb,e;
	double p;
	scanf("%d",&m);
	while(m--){
		scanf("%d",&s);
		scanf("%d",&y);
		scanf("%d",&n);
		maxs=0;
		for(i=0;i<n;i++){
			ts=0;
			tb=0;
			e=0;
			scanf("%d %lf %d",&f,&p,&k);
			if(f){ //bi
				for(tb=s,j=0;j<y;j++){
					tb=tb*(1.0+p)-k;			
				}				
				if(tb>maxs)maxs=tb;
			}else{ //single
				for(ts=s,j=0;j<y;j++){
					e+=ts*p;
					ts-=k;
				}
				if(ts+e>maxs)maxs=ts+e;
			}
		}
		printf("%d\n",maxs);
	}
	return 0;
}