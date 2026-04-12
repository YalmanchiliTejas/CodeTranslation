#include<cstdio>
#include<cstring>
char s[10];
int main(){
	scanf("%s",s);
	int len=strlen(s);
	for(int i=1;i<len;i++){
		if(s[i]=='C'&&s[i-1]=='A') {
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}