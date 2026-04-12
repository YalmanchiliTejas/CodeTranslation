#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void)
{
	int a,s[12],d[12],f,g=0,h,i,j,k=0;
	for(i=0;i<12;i++){
		s[i]=0;
		d[i]=0;
	}
	for(i=0;i<12;i++){
		scanf("%d",&a);
		f=0;
		for(j=0;j<k;j++){
			if(a==s[j]){
				f=1;
				d[j]++;
				if(d[j]==4){
					s[j]=0;
					d[j]=0;
					g++;
				}
				break;
			}
		}
		if(f==0){
			s[k]=a;
			d[k]++;
			k++;
		}
	}
	if(g==3) printf("yes\n");
	else printf("no\n");
	return 0;
}