#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main(void)
{
	char s[6];
	int n,i,j,w,z;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		z=1;
		int a[4]={4,1,5,1};
		for(i=0;i<n;i++){
			scanf("%s",s);
			if(s[0]=='N'){
				w=a[2]; a[2]=a[3]; a[3]=7-w; a[1]=a[3];
			}
			else if(s[0]=='E'){
				w=a[1]; a[1]=a[0]; a[0]=7-w; a[3]=a[1];
			}
			else if(s[0]=='W'){
				w=a[0]; a[0]=a[1]; a[1]=7-w; a[3]=a[1];
			}
			else if(s[0]=='S'){
				w=a[3]; a[3]=a[2]; a[2]=7-w; a[1]=a[3];
			}
			else if(s[0]=='L'){
				w=a[0]; a[0]=a[2]; a[2]=7-w; 
			}
			else if(s[0]=='R'){
				w=a[2]; a[2]=a[0]; a[0]=7-w; 
			}
//			printf("%d %d %d %d\n",a[0],a[1],a[2],a[3]);
			z+=a[1];
		}
		printf("%d\n",z);
	}
	return 0;
}