#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
	char c[2], s[6] = "aeiou";
	scanf("%s", c);
	if(find(s, s + 5, c[0]) != s + 5) puts("vowel");
	else puts("consonant");
	return 0;
}