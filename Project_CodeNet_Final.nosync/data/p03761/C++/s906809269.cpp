#include<stdio.h>
int main(){
	int n;
	char S[50][50];
	int num[26];
	int num2[26];
	int basenum = (int)('a');
	for(int h=0;h<26;h++){
		num[h]=99;
	}
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf(" %s",S[i]);
	}
	for(int j=0;j<n;j++){
		for(int jj=0;jj<26;jj++){
			num2[jj]=0;
		}
		for(int k=0;k<50;k++){
			if(S[j][k]==0) break;
			int alphabet;
			alphabet = (int)S[j][k];
			num2[alphabet - basenum]++;
		}
		for(int m=0;m<26;m++){
			if(num2[m]<num[m])num[m]=num2[m];
		}
	}
	for(int p=0;p<26;p++){
		char moji = (char)(int)('a'+p);
		for(int q=0;q<num[p];q++){
			printf("%c",moji);
		}
	}
	printf("\n");
}