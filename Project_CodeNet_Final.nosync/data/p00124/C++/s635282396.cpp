#include<stdio.h>
#include<string.h>
int main(void)
{
	char na[10][21],x[21];
	int n,w[10],l[10],d[10],a[10],i,j,y,flg;
	flg=1;
	scanf("%d",&n);
	while(n!=0){
		for(i=0;i<n;i++){
			scanf("%s %d %d %d",na[i],&w[i],&l[i],&d[i]);
			l[i]=w[i]*3+d[i];
			a[i]=i;
		}
		for(i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				if(l[i]<l[j] || l[i]==l[j] && a[i]>a[j]){
					y=l[i];  l[i]=l[j];  l[j]=y;
					y=a[i];  a[i]=a[j];  a[j]=y;
					strcpy(x,na[i]);  strcpy(na[i],na[j]);  strcpy(na[j],x);
				}
			}
		}
		if(flg==0)  printf("\n");
		for(i=0;i<n;i++)  printf("%s,%d\n",na[i],l[i]);
		flg=0;
		scanf(" %d",&n);
	}
	return 0;
}