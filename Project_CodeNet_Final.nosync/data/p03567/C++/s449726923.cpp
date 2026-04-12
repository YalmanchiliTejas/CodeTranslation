#include <bits/stdc++.h>
using namespace  std;

char s[10];

int main(){
	scanf("%s", s);
	bool ans  = 0;
	for(int i=0;i<strlen(s)-1;i++){
		if(s[i] == 'A' && s[i+1] == 'C') ans = 1;
	}
	if(ans) printf("Yes");
	else printf("No");
}