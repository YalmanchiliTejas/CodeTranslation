#include<bits/stdc++.h>
using namespace std;

char p[100005];
int S[100005],P[100005],n; 

int main(){
	scanf("%d%s",&n,&p);
	for(int i=0;i<n;i++){
		if(p[i]=='o') P[i+1]=0;
		else P[i+1]=1;
	}
	P[n+1]=P[1];
	for(int i=0;i<8;i++){
		S[0]=i&1;
		S[1]=(i>>1)&1;
		S[2]=(i>>2)&1;
		for(int j=2;j<=n+1;j++){
			S[j+1]=S[j-2]^P[j];
		}
		if((S[0]^S[1]^S[n]^S[n+1])||(S[1]^S[2]^S[n+1]^S[n+2])) continue;
		for(int j=1;j<=n;j++){
			printf("%c",(S[j-1]^S[j])?'W':'S');
		}
		return 0;
	}
	printf("-1\n");
	return 0;
} 