#include <cstdio>
#include <cstring>

char s[6];
bool f;

int main(){
	scanf("%s", s);
	for(int i=0; i<strlen(s)-1; ++i)
		if(s[i] == 'A' && s[i+1] == 'C')
			f = true;
	if(f) printf("Yes\n");
	else printf("No\n");
}