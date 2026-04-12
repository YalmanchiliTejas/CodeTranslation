#include<cstdio>
int main(void){
	char a[10];
	scanf("%s", a);
	if (a[0] == 'a' || a[0] == 'i' || a[0] == 'u' || a[0] == 'e' || a[0] == 'o') printf("vowel\n");
	else printf("consonant\n");
}