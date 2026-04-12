#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char ch[111];
int i,j,k,n;
int main(){
	scanf("%s",ch);n=strlen(ch);
	for (i=k=0;i<n-1;i++)
	 if (ch[i]=='A'&&ch[i+1]=='C') k=1;
	puts(k?"Yes":"No");
	return 0;
}