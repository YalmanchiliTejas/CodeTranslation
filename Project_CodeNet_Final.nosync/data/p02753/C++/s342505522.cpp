#include<cstdio>
using namespace std;
char s[5];
int a[150];
int main() {
	scanf("%s",s+1);
	for(int i=1;i<=3;i++) a[(int)s[i]]++;
	if(a['A']&&a['A']<3) puts("Yes");
	else puts("No");
	return 0;
}