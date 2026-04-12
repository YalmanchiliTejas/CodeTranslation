#include <bits/stdc++.h>
using namespace std;
char s[5];
int main() {
	//freopen("in.txt","r",stdin);
	scanf("%s",s);
	int a=0,b=0;
	for(int i=0;s[i];i++) {
		if(s[i]=='A') a++;
		else b++;
	}
	printf("%s\n",a&&b?"Yes":"No");
	return 0;
}