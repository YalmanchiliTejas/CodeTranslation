#include <bits/stdc++.h>
using namespace std;
#define lor(a,b,c) for(register int a=b;a<=c;++a)
#define ror(a,b,c) for(register int a=c;a>=b;--a)
typedef long long ll;

const int MAXN=105,MAXT=MAXN<<1,INF=0x3f3f3f3f;
const ll MOD=1e9+7;

int n,h[MAXN];
int tot,bor[MAXT][2],son[MAXT][MAXT],top[MAXT],bot[MAXT];
ll dp1[MAXN],dp2[MAXN];

template <typename T> inline T read(){
	char tmp=getchar(); T sum=0; bool flag=false;
	while(tmp<'0'||tmp>'9'){
		if(tmp=='-') flag=true; tmp=getchar();
	}
	while(tmp>='0'&&tmp<='9'){
		sum=(sum<<1)+(sum<<3)+tmp-'0'; tmp=getchar();
	}
	return flag?-sum:sum;
}

template <typename T> inline void inc(T &a,T b){
	(a+=b)>=MOD?a-=MOD:a;
}

inline ll qsm(ll a,ll b){
	ll ans=1ll;
	while(b){
		if(b&1) (ans*=a)%=MOD; (a*=a)%=MOD; b>>=1;
	}
	return ans;
}

int main(){
	n=read<int>(); lor(i,1,n) h[i]=read<int>();

	tot=1; bor[tot][0]=1; bor[tot][1]=n;
	int it=tot;
	while(it<=tot){
		bool same=true; int minn=h[bor[it][0]];
		lor(i,bor[it][0]+1,bor[it][1]){
			if(h[i]!=h[i-1]) same=false; minn=min(minn,h[i]);
		}
		top[it]=minn;
		if(!same){
			int pre=-1;
			lor(i,bor[it][0],bor[it][1]){
				if(h[i]==minn){
					if(pre!=-1) ++tot,son[it][++son[it][0]]=tot,bor[tot][0]=pre,bor[tot][1]=i-1,bot[tot]=minn;
					pre=-1;
				}
				else{
					if(pre==-1) pre=i;
				}
			}
			if(pre!=-1) ++tot,son[it][++son[it][0]]=tot,bor[tot][0]=pre,bor[tot][1]=bor[it][1],bot[tot]=minn;;
		}
		++it;
	}

	ror(k,1,tot){
		ll st1=1ll,st2=1ll;
		ll uncover=bor[k][1]-bor[k][0]+1,h=top[k]-bot[k];
		lor(i,1,son[k][0]){
			int v=son[k][i];
			uncover-=bor[v][1]-bor[v][0]+1;
			(st1*=dp1[v]+dp2[v])%=MOD;
			(st2*=dp1[v])%=MOD;
		}
		dp1[k]=st2*qsm(2,h)%MOD;
		(dp2[k]=qsm(2,uncover)*st1%MOD+(qsm(2,h)+MOD-2)%MOD*st2%MOD)%=MOD;
	}

	printf("%lld\n",dp2[1]);

	return 0;
}