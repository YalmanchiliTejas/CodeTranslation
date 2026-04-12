#include<cstdio>
#include<cstring>
#include<algorithm>
char s[15];
int len;
int main(){
	scanf("%s",s+1); len=strlen(s+1);
	for(int i=1;i<len;i++)if(s[i]=='A'&&s[i+1]=='C') return printf("Yes\n"),0;
	printf("No\n");
	return 0;
}