#include<cstdio>
using namespace std;
char str[1000];
int main(){
	scanf("%s",str+1);
	for(int i=1;i<=5;i++)
		if(str[i]=='A'&&str[i+1]=='C')
		{
			printf("Yes\n");
			return 0;
		}
	printf("No\n");
	return 0;
}
