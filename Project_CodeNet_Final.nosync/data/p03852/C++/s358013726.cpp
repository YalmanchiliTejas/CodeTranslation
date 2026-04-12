#include <cstdio>

//biginner49

int main(){
	char c;
	scanf("%c", &c);
	char k[5] = { 'a', 'i', 'o', 'u', 'e' };
	for (int i = 0; i < 5; i++){
		if (c == k[i]){
			printf("vowel\n");
			return 0;
		}
	}
	printf("consonant\n");
	return 0;
}