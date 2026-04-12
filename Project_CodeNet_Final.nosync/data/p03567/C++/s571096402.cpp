#include <bits/stdc++.h>

using namespace std;

#define N 100000

char str[N + 2];

int main(){
	int n, i;

	scanf("%[^\r\n]%n", str, &n);

	for (i = 0; i < n - 1; i++){
		if (str[i] == 'A' and str[i + 1] == 'C'){
			break;
		}
	}

	if (i < n - 1){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}

	return 0;
}