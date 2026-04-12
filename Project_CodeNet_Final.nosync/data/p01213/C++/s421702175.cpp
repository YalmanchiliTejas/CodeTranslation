//2090
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)

const int MAX_LEN=300;

char S[MAX_LEN+1];
int len;

int dp[MAX_LEN+1][MAX_LEN+1];
char out[MAX_LEN+1];

int lcs(int sp){
	int len1=sp;
	int len2=len-sp;
	FOR(i,1,len1+1){
		FOR(j,1,len2+1){
			if (S[i-1]==S[sp+j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[len1][len2];
}

int main(){
	do{
		scanf("%s",S);
		if (S[0]!='#'){
			len=strlen(S);
			int ans=0;
			int sp;
			FOR(i,1,len){
				int l=lcs(i);
				if (l>ans){
					ans=l;
					sp=i;
				}
			}
			lcs(sp);
			int i=sp,j=len-sp;
			stack<char> st;
			while (ans>0){
				if (S[i-1]==S[sp+j-1]){
					ans--;
					st.push(S[i-1]);
					i--;
					j--;
				}
				else{
					if (dp[i-1][j]==dp[i][j]){
						i--;
					}
					else{
						j--;
					}
				}
			}
			while (!st.empty()){
				printf("%c",st.top());
				st.pop();
			}
			printf("\n");
		}
	}while(S[0]!='#');
	return 0;
}