#include<stdio.h>

int main(){
	double a,b,unyou[100][5],syoki,max;
	int i,j,k,m,nen,n;
	
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%lf%d%d",&syoki,&nen,&n);
//		printf("i %d\n",i);
		for(j=0;j<n;j++){
			scanf("%lf%lf%lf",&unyou[j][0],&unyou[j][1],&unyou[j][2]);
			a=syoki;
			b=0;
//			printf("j %d\n",j);
			switch(int(unyou[j][0])){
			case 0:
				for(k=0;k<nen;k++){
//					printf("k %d nen %d\n",k,nen);
					b+=int(a*unyou[j][1]);
					a=a-unyou[j][2];
				}
				unyou[j][3]=a+b;
//				printf("%d %lf\n",j,unyou[j][3]);
				break;
			case 1:
				for(k=0;k<nen;k++){
//					printf("k %d nen %d\n",k,nen);
					b=int(a*unyou[j][1]);
					a=a-unyou[j][2]+b;
				}
				unyou[j][3]=a;
//				printf("%d %lf\n",j,unyou[j][3]);
				break;
			}
		}
		
		
		max=0;
		for(j=0;j<n;j++){
			if(max<unyou[j][3]){
				max=unyou[j][3];
			}
		}
		printf("%.0f\n",max);
	}
	return 0;
}