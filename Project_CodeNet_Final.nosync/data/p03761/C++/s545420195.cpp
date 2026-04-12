#include <cstdio>
#include <cstring>

int main(){
	int n;
	char S[50][52];
	char A[256];

	int alpha[50][26];
	int min[26];

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",S[i]);
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<26;j++){
			alpha[i][j] = 0;
			min[j] = 0;
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<strlen(S[i]);j++){
			alpha[i][S[i][j]-'a'] += 1;
		}
	}

	for(int i=0;i<26;i++){
		min[i] = alpha[0][i];
		for(int j=0;j<n;j++){
			if(min[i]>alpha[j][i]){
				min[i] = alpha[j][i];
			}
		}
	}

	for(int i=0;i<26;i++){
		for(int j=0;j<min[i];j++){
			printf("%c",('a'+i));
		}
	}
	printf("\n");

	return 0;
}
