#include<cstdio>
#include<cstring>
using namespace std;
const long long mod=1e9+7;
char s[105];
int k;
int digit[105];
long long f[105][5];
long long dfs(int pos,int num,bool res){
	if (num>k) return 0;
	if (pos==0&&num==k) return 1;
	if (!res&&f[pos][num]!=-1) return f[pos][num];
	int maxn=res?digit[pos]:9;long long ans=0;
	for (register int i=0;i<=maxn;++i){
		if (i==0) ans=(ans+dfs(pos-1,num,res&&i==maxn))%mod;
		else ans=(ans+dfs(pos-1,num+1,res&&i==maxn))%mod;
	}
	if (!res) f[pos][num]=ans;
	return ans;
}
int main(){
	memset (f,-1,sizeof (f));
	scanf ("%s",s+1);scanf ("%d",&k);
	int len=strlen(s+1);
	int w=len;
	digit[0]=0;
	while (digit[0]<=len){++digit[0];digit[digit[0]]=s[w]-'0';--w;}
	printf ("%lld\n",dfs(digit[0]-1,0,1));
	return 0;
}