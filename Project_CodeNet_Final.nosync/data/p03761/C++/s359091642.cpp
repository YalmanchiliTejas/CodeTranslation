#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;





int main(){

	int table[26];
	for(int i = 0; i < 26; i++){

		table[i] = BIG_NUM;
	}

	int N;
	scanf("%d",&N);

	char buf[55];
	int work[26];

	for(int i = 0; i < N; i++){

		scanf("%s",buf);
		for(int k = 0; k < 26; k++){

			work[k] = 0;
		}
		for(int k = 0; buf[k] != '\0'; k++){

			work[buf[k]-'a']++;
		}
		for(int k = 0; k < 26; k++){

			table[k] = min(table[k],work[k]);
		}
	}

	for(int i = 0; i < 26; i++){
		if(table[i] == 0)continue;

		for(int k = 0; k < table[i]; k++){

			printf("%c",'a'+i);
		}
	}
	printf("\n");
	return 0;
}
