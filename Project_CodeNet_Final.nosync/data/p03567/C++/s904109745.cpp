#include<stdio.h>
#include<string.h>
char ch[10];
int main(){
	int i,len;
	while(scanf("%s",ch)!=EOF){
		int flag=0;
		len=strlen(ch);
		for(i=0;i<len-1;i++){
			if(ch[i]=='A'&&ch[i+1]=='C'){
				flag=1;
				break;
			}
		}
		if(flag==1){
			printf("Yes\n");
		}
		else
			printf("No\n");
	}
	return 0;
}