#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=5+2;
char str[maxn];
int main(){
	scanf("%s",str+1);
	int len=strlen(str+1);
	for (int i=1;i<len;i++)
		if (str[i]=='A'&&str[i+1]=='C'){
			printf("Yes");
			return 0;
		}
	printf("No");
	return 0;
}