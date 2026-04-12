#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, K, i;
	scanf("%d", &N);
	string S;
	cin >> S;
	scanf("%d", &K);
	for(i = 0; i < N; i++){
		if(S[i] == S[K - 1]){
			printf("%c", S[i]);
		}
		else{
			printf("*");
		}
	}
	printf("\n");
	return 0;
}