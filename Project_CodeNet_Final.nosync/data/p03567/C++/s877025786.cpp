#include <cstdio>
using namespace std;
char s[10];
int main(){
	int i;
	
	scanf("%s", s);
	for(i=0; s[i]; i++){
		if(s[i]=='A' && s[i+1]=='C'){
			printf("Yes");
			return 0;
		}
	}
	printf("No");
	return 0;
}