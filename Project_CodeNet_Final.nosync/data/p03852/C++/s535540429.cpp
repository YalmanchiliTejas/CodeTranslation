#include<cstdio>
int main(){
	char X;
	scanf("%c",&X);
	if(X == 'a' || X == 'e' || X == 'i' || X == 'o' || X == 'u')
		printf("vowel\n");
		else printf("consonant\n");
		return 0;
}