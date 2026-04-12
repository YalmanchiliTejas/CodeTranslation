#include <cstdio>
#include <cstring>
int main(){
	bool a=0;
	char s[5];
	scanf("%s",s);
	for(int i=0;i<=strlen(s);i++){
		if(s[i]=='C'&&a){
			printf("Yes\n");
			return 0;
		}
		a=0;
		if(s[i]=='A'){
			a=1;
		}
	}
	printf("No\n");
	return 0;
}