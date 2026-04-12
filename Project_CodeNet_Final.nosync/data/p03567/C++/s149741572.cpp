#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int len;
char s[100001];
void dfs(int pos){
	if(pos == len){
		printf("No");
		return;
	}
	if(s[pos] == 'A'){
		if(s[pos + 1] == 'C'){
			printf("Yes");
			return;
		}
	}
	dfs(pos + 1);
}
int main(){
	scanf("%s",s);
	len = strlen(s);
	dfs(0);
	return 0;
}