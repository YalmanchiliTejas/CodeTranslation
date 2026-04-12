#include<cstdio>
#include<cstring>
using namespace std;
char a[10],len;
int main(void){
	register int i;
	scanf("%s",a+1);
	len=strlen(a+1);
	for(i=1;i<len;++i)
		if(a[i]=='A'&&a[i+1]=='C'){
			puts("Yes");
			return 0;
		}
	puts("No");
	return 0;	
}