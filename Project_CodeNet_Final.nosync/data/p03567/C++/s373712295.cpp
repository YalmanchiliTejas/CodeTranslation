#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char s[10];
int main() {
	scanf("%s",s+1);
	int len=strlen(s+1),cck=false;
	if (len>1&&s[1]=='A'&&s[2]=='C') cck=true;
	if (len>2&&s[2]=='A'&&s[3]=='C') cck=true;
	if (len>3&&s[3]=='A'&&s[4]=='C') cck=true;
	if (len>4&&s[4]=='A'&&s[5]=='C') cck=true;
	puts(cck?"Yes":"No");
	return 0;
}