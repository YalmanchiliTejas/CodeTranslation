#include<iostream>
#include<cstdio>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=200200,P=1e9+7;
int n,m,ans,lim,all,mxo;
int b[N],f[N],s[N];
char S[N];
void work(int w){
	f[0]=s[0]=1;//cout<<w<<' '<<lim<<'\n';
	if(w==1){
		f[1]=0;s[1]=1;
		FOR(i,2,n){
			f[i]=s[i-2];
			s[i]=(s[i-1]+f[i])%P;
			//cout<<f[i]<<' ';
		}
	}
	else{
		FOR(i,1,n){
			f[i]=(s[i-1]-(i-lim-1<0?0:s[i-lim-1])+P)%P;
			s[i]=(s[i-1]+f[i])%P;
			//cout<<f[i]<<'\n';
		}
	}
	FOR(i,1+(w==1),min(lim,n)) (ans+=1ll*i*f[n-i]%P)%=P;
	cout<<w*ans%P<<'\n';
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d%s",&n,&m,S+1);
	ROF(i,m,1) b[i]=S[i]=='R'^S[1]=='B';
	all=1;
	FOR(i,1,m) all&=b[i];
	if(all) return lim=n,ans=1,work(1),0;
	FOR(i,1,m)if(!b[i]){lim=i-!(i%2);break;}
	for(int l=1,r=1;l<=m;l=r){
		while(r<=m && b[r]==b[l]) r++;
		if(b[l]==0) continue;
		if((r-l&1) && l!=1 && r<=m) lim=min(lim,r-l);
	}
	lim=lim+1>>1;
	if(n&1) return puts("0"),0;
	n/=2;work(2);
}
