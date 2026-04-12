#include <cstdio>
#include <cstring>
using namespace std;
char a[3]; 
int main(){
	scanf("%s",a);
	if(!strcmp(a,"AAA")||!strcmp(a,"BBB"))printf("No\n");
	else printf("Yes\n");
	return 0;
}