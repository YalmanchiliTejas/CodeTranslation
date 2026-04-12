#include<bits/stdc++.h>
using namespace std;
int main(){
	char inp[10];
	scanf("%s",inp);
	int xb;
	for(xb=0;xb<strlen(inp)-1;++xb){
		if(inp[xb]=='A'&&inp[xb+1]=='C'){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No");
	return 0;
}