#include<cstdio>

int main(){
	char c;
	char boin[] = "aiueo";
	scanf("%c",&c);
	for(int i=0;i<5;i++){
		if(boin[i]==c){
			printf("vowel\n");
			return 0;
		}
	}
	printf("consonant\n");
}
