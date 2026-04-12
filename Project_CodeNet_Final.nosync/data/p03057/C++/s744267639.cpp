#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdlib>
#define LL long long
#define LD long double
using namespace std;
const int NN=200000 +117;
const int MM=200000 +117;
int read(){
	int fl=1,x;char c;
	for(c=getchar();(c<'0'||c>'9')&&c!='-';c=getchar());
	if(c=='-'){fl=-1;c=getchar();}
	for(x=0;c>='0'&&c<='9';c=getchar())
		x=(x<<3)+(x<<1)+c-'0';
	return x*fl;
}
void open(){
	freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
}
void close(){
	fclose(stdin);
	fclose(stdout);
}


int m,n;
char s[NN]={};
bool a[NN]={};
LL f[NN]={};
const int mod=1e9+7;
void simple(int n){
	f[0]=1;
	f[1]=1;
	for(int i=2;i<=n;++i){
		f[i]=(f[i-1]+f[i-2])%mod;
	}
	LL ans=1+f[n-2];
	for(int i=2;i<=n;++i){
		ans+=f[n-i];
		ans%=mod;
	}
	printf("%lld\n",ans);
}
void solve(int n,int lim){
	if(n%2!=0){
		printf("0\n");
		return ;
	}
	n/=2;
	lim=(lim+1)/2;
	f[0]=1;
	LL ans=0;
	for(int i=1;i<=n;++i){
		f[i]=2*f[i-1];
		if(i-lim-1>=0)f[i]-=f[i-lim-1];
		f[i]%=mod;
	}
	for(int i=1;i<=min(n,lim);++i){
		ans+=2*i*(f[n-i]-f[n-i-1]);
		ans%=mod;
	}
	ans=(ans+mod)%mod;
	printf("%lld\n",ans);
}
int main(){
	//open();
	n=read();
	m=read();
	scanf("%s",s+1);
	bool same=1;
	for(int i=1;i<=m;++i){
		a[i]=(s[i]==s[1]);
		if(!a[i])same=0;
	}
	int lim=0;
	if(same){
		simple(n);
	}
	else{
		int pos=1;
		int cnt=0;
		bool first=0;
		int lim=0;
		for(pos=1;pos<=m;++pos){
			if(a[pos])++cnt;
			else{
				if(!first){
					first=1;
					lim=cnt+1-(cnt&1);
				}
				else{
					if(cnt&1)lim=min(lim,cnt); 
				}
				cnt=0;
			}
		}
		solve(n,lim);
	}
	close();
	return 0;
}