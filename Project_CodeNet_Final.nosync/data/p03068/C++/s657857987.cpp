#include <cstdio>
#include <algorithm>
using namespace std;

int len,k;
char c[105];

int main(void){
	scanf("%d",&len);
	scanf("%s",c);
	scanf("%d",&k);
	k--;
	for(int i=0;i<len;i++)
	if(c[k]!=c[i])printf("*");
	else printf("%c",c[i]);
	printf("\n");
}