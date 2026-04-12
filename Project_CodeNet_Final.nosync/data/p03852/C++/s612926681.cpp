#include <cstdio>
using namespace std;

char t[2];

int main(){
	scanf("%s", t);
	if(t[0] == 'a' || t[0] == 'e' || t[0] == 'i' || t[0] == 'o' || t[0] == 'u') printf("vowel\n");
	else printf("consonant\n");
	return 0;
}