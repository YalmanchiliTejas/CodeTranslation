#include <bits/stdc++.h>

using namespace std;

char s[10];

int main(){
	scanf("%s", s);
	
	int l = strlen(s);
	
	for(int i = 0; i < l - 1; i++){
		if(s[i] == 'A' && s[i + 1] == 'C')
		return 0 * printf("Yes\n");
	}
	
	printf("No\n");
}
