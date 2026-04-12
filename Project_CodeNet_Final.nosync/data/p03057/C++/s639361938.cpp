#include<bits/stdc++.h>
const int N=200005,M=1000000007;
using namespace std;
int n,m,l=1,k=N,ls,f[N],s[N];
char S[N],fi;
int main(){
	scanf("%d%d%s",&n,&m,S);
	fi=S[0];
	for(int i=1;i<m;i++)
	if(S[i]!=S[i-1])
	if(S[i]^fi){
		if(ls==0||i-ls&1)
		k=min(k,i-ls);
	}else ls=i;
	if(k<N){
		if(n&1)return puts("0"),0;
		k=k+2>>1,n>>=1;
	}else l++;
	for(int i=l;i<=n;i++)
	f[i]=(s[i-l]+(i>k?-s[i-k-1]:(3ll-l)*i))%M,s[i]=(s[i-1]+f[i])%M;
	printf("%d",(f[n]+l-1+M)%M);
}