#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
char s[100001];
int main() {
	scanf("%s",s);
	int len=strlen(s);
	bool judge=0;
	for (int i=0;i<len-1;i++)
		if (s[i]=='A'&&s[i+1]=='C') {
			judge=1;
			break;
		}
	if (judge) printf("Yes\n");
		else printf("No\n");
	return 0;
}