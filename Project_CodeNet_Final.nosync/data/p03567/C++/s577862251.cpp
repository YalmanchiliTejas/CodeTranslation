#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
char s[10];
int main() {
	int flag = 0;
	scanf("%s", s);
	int len = strlen(s);
	for(int i = 0; i < len - 1; i++) {
		if(s[i] == 'A' && s[i + 1] == 'C')flag = 1;
	}
	if(flag)printf("Yes\n");
	else printf("No\n");
	return 0;
}