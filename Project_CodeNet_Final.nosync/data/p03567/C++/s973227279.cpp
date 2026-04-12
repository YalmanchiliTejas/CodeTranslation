#include<cstdio>
int main(){
	char s[6]={};
	scanf("%s",s);
	int x=0;
	for(int i=0;i<5;i++){
		if(s[i]=='A' && s[i+1]=='C')x=1;
	}
	if(x==1)printf("Yes");
	else printf("No");
	return 0;
}