#include<stdio.h>
char t[100];
int c(char t){
	if(t=='y'||t=='u'||t=='i'||t=='o'||t=='p'||t=='h'||t=='j'||t=='k'||t=='l'||t=='n'||t=='m')return 1;
	return 0;
}
int main(){
	while(1){
		scanf("%s",t);
		if(t[0]=='#')return 0;
		int now=c(t[0]);
		int ret=0;
		for(int i=1;t[i];i++){
			int p=c(t[i]);
			if(now!=p)ret++;
			now=p;
		}
		printf("%d\n",ret);
	}
}