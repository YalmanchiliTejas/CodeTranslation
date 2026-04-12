#include<cstdio>
#include<cstring>

using namespace std;

char s[100]; 

int main() {
	scanf("%s", s+1);
	for(int i = 1; i < strlen(s+1); ++i)
	if(s[i] == 'A' && s[i+1] == 'C') {puts("Yes"); return 0;}
	puts("No");
	return 0;
}