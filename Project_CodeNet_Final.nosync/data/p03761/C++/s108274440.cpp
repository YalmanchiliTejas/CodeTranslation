#include<stdio.h>
#include<string.h>

int main() {
	int m, i, j, k, tong[27], tong1[27];
	char a[1000];
	while(scanf("%d",&m)!=EOF) {
		memset(tong,0,sizeof(tong));
		memset(tong1,0,sizeof(tong));
		m--;
		scanf("%s",a);
		j = strlen(a);
		for(i=0;i<j;i++) {
			tong[a[i]-'a']++;
		}
		while(m--){
			scanf("%s",a);
			j = strlen(a);
			for(i=0;i<j;i++) {
				tong1[a[i]-'a']++;
			}
			for(i=0;i<26;i++) {
				if(tong1[i]<tong[i]) {
					tong[i]=tong1[i];
				}
			}
			memset(a,0,sizeof(a));
			memset(tong1,0,sizeof(tong1));
		}
		for(i=0;i<27;i++) {
		//	printf("%d ",tong[i]);
			if(tong[i]>0) {
				tong[i]-=1;
				printf("%c",i+'a');
				i--;
			}
			else{
			//	printf(",,,");
			}
		}
		printf("\n");
	}
}