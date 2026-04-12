#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
	char s[10];
	int flag = 0;
	scanf("%s",s);
	for(int i = 0 ; i < strlen(s) - 1 ; i++){
		if(s[i] == 'A' && s[i + 1] == 'C') flag = 1;
	}
	if(flag) printf("Yes\n");
	else printf("No\n");
}