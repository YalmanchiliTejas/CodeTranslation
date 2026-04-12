#include<bits/stdc++.h>
using namespace std;
char p[100010];
long long S[100010],P[100010],n;
int main(){
	cin>>n;
	scanf("%s",p);
	long long i,j;
	for(i=0;p[i];i++){
		if(p[i]=='o')P[i+1]=0;
		else P[i+1]=1;
	}
	P[n+1]=P[1];
	for(i=0;i<8;i++){
		S[0]=i&1;
		S[1]=(i>>1)&1;
		S[2]=(i>>2)&1;
		for(j=2;j<=n+1;j++)S[j+1]=S[j-2]^P[j];
		if(S[0]^S[n]^S[1]^S[n+1]||S[1]^S[n+1]^S[2]^S[n+2])continue;
		for(j=1;j<=n;j++)cout<<(S[j]^S[j-1]?'W':'S');
		return 0;
	}
	cout<<-1;
	return 0;
}