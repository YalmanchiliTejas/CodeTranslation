#include<cstdio>
int main() {
	char a[6] = "aeiou", c;
	scanf("%c", &c);
	for (int i = 0; i < 5; i++) {
		if (a[i] == c) {
			printf("vowel");
			return 0;
		}
	}
	printf("consonant");
	return 0;
}