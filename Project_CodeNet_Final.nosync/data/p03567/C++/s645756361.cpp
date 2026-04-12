#include <cstdio>
#include <cstring>

char c[6];

int main(){
	scanf("%s",c);
	if(strlen(c)<2){
		puts("No");
		return 0;
	}
	for(int i=0;i<strlen(c)-1;++i){
		if(c[i]=='A' && c[i+1]=='C'){
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}