#include <cstdio>
#include <cstdlib>
#define REP(i,n) for (int i=0;i<(n);i++)
int main(){
	int N;
	char S[52][52]={};
	int k[52][26]={};
	int sum[26];REP(i,26){sum[i]=114514;}
	scanf("%d",&N);
	REP(i,N){scanf("%s",S[i]);}
	REP(i,N){for(int j=0;26&&S[i][j]!=0;j++){k[i][S[i][j]-'a']++;}REP(j,26){if(sum[j]>k[i][j]){sum[j]=k[i][j];}}}
	

	REP(i,26){REP(j,sum[i]){printf("%c",'a'+i);}}printf("\n");
	system("pause");
	return 0;
}
