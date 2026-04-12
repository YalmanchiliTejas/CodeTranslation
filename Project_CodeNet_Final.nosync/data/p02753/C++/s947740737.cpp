#include <cstdio>
using namespace std;
int main(){
	char str[3];
	scanf("%s",str);
	bool test1(false),test2(false);
	for(int i=0;i<=3;i++){
			if(str[i]=='A')test1 = true;
			if(str[i]=='B')test2 = true;
		}
	if(test1 && test2)printf("Yes");
	else printf("No");	
	return 0;
	}
