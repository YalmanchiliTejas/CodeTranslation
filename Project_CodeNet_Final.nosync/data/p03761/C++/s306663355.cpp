#include <bits/stdc++.h>
using namespace std;

char s[100];
int n;
int f[100][30];
int ans[30];

int main(){
	scanf("%d",&n);
	for ( int i= 0; i < n; i++){
		scanf("%s",&s);
		int m = strlen(s);
		for ( int j = 0; j < m; j++ ){
			f[i][s[j]-'a']++;
		}
	}	
	
	for ( int i = 0; i < 26; i++ ){
		ans[i] = f[0][i];
	}
	for ( int i =1 ; i < n; i++){
		for ( int j = 0; j < 26; j++) ans[j] = min(ans[j],f[i][j]);
	}
	
	for ( int i = 0; i < 26; i++){
		while ( ans[i] > 0 ){
			printf("%c",i+'a');
			ans[i]--;
		}
	}
	puts("");
	return 0;
}