#include<stdio.h>
int main(void)
{
    int i,a[5],b[5],c,d;
	char mise[5]={'A','B','C','D','E'};
	while(1){
	    c=0;
		scanf("%d %d",&a[0],&b[0]);
	    if(a[0]==0&&b[0]==0) break;
		for(i=1;i<5;i++){
		    scanf("%d %d",&a[i],&b[i]);
		}
		for(i=0;i<5;i++){
		    if(c<a[i]+b[i]){
			    c=a[i]+b[i];
				d=i;
			}
		}
		printf("%c %d\n",mise[d],c);
	}
	return 0;
}