#include <bits/stdc++.h>
using namespace std;

int main (){
	char S[10];
	scanf("%s", S);
	for(int i = 0; S[i + 1]; ++i){
		if(S[i] == 'A' && S[i + 1] == 'C'){
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}
