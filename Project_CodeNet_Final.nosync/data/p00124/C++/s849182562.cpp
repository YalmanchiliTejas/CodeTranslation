#include<stdio.h>
int main(void)
{
	int n,i,b[100],c[100],x,y,z,j,max,cnt;
	char a[100][100];
	scanf("%d",&n);
	cnt=0;
	while(n!=0){
		if(0<cnt) printf("\n");
		for(i=0;i<n;i++) b[i]=0;
		for(i=0;i<n;i++){
			scanf("%s %d %d %d",a[i],&x,&y,&z);
			b[i]=x*3+z;
		}
		for(i=0;i<n;i++){
			max=-1;
			for(j=0;j<n;j++){
				if(max<b[j]) max=b[j];
			}
			for(j=0;j<n;j++){
				if(max==b[j]){
					printf("%s,%d\n",a[j],b[j]);
					b[j]=-2;
				}
			}	
		}
		cnt++;
		scanf("%d",&n);
	}
	return 0;
}