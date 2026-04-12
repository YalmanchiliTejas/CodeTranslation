#include<iostream>
#include<cstdio>
using namespace std;
#define NN 70000+117
#define mod 998244353
#define LL long long
#include<cstring>
char a[NN]={};
char b[NN]={};
int n,len;
struct seq{
	LL x[NN]={};
}s;
LL fact[NN]={};
int all,acnt,bcnt;
int fan[NN]={};
int rev[NN]={};
LL kkk(LL a,LL b){
	LL ret=1;
	while(b){
		if(b&1){
			(ret*=a)%=mod;
		}
		b>>=1;
		(a*=a)%=mod;
	}
	return ret;
}
LL reverse(LL a){
	return kkk(a,mod-2);
}
seq tp;
void NTT(seq &a,int sym){
	for(int i=1;i<len;++i){
		if(i<rev[i])swap(a.x[i],a.x[rev[i]]);
	}
	LL ORT=3;
	if(sym==-1)ORT=reverse(ORT);
	for(int d=1;d<len;d<<=1){
		LL rt=kkk(ORT,(mod-1)/(d*2));
		for(int st=0,gap=d<<1;st<len;st+=gap){
			LL r=1;
			for(int i=0;i<d;++i,(r*=rt)%=mod){
				LL y=a.x[st+i],z=r*a.x[st+d+i]%mod;
				a.x[st+i]=(y+z)%mod;
				a.x[st+d+i]=(mod+y-z)%mod;
			}
		}
	}
	if(sym==-1){
		LL di=reverse(len);
		for(int i=0;i<len;++i){
			(a.x[i]*=di)%=mod;
		}
	}
}
void multi(seq &a,seq &b){
	NTT(a,1);
	NTT(b,1);
	for(int i=0;i<len;++i){
		(a.x[i]*=b.x[i])%=mod;
	}
	NTT(a,-1);
}
LL ksm(seq &a,LL b){
	seq ret;
	memset(ret.x,0,sizeof(ret.x));
	ret.x[0]=1;
	for(int i=0;i<len;++i){
		rev[i]=(rev[i>>1]>>1)|(i&1?len>>1:0);
	}
	while(b){
		if(b&1){
			for(int i=0;i<=all;++i){
				tp.x[i]=a.x[i];
			}
			for(int i=all+1;i<len;++i){
				tp.x[i]=0;
			}
			multi(ret,tp);
			for(int i=all+1;i<len;++i){
				ret.x[i]=0;
			}
		}
		b>>=1;
		for(int i=0;i<=all;++i){
			tp.x[i]=a.x[i];
		}
		for(int i=all+1;i<len;++i){
			tp.x[i]=0;
		}
		multi(a,tp);
		for(int i=all+1;i<len;++i){
			a.x[i]=0;
		}
	}
	LL ans=0;
	for(int i=0;i<=all;++i){
		(ans+=ret.x[i])%=mod;
	}
	return ans;
}
int main(){
	//freopen("test.in","r",stdin);
	scanf("%s",a+1);
	scanf("%s",b+1);
	acnt=0;
	bcnt=0;
	all=0;
	n=strlen(a+1);
	for(int i=1;i<=n;++i){
		a[i]-='0';
		b[i]-='0';
	}
	for(int i=1;i<=n;++i){
		if(!a[i]&&b[i]){
			++bcnt;
		}
		else if(a[i]&&!b[i]){
			++acnt;
		}
		else if(a[i]&&b[i]){
			++all;
		}
	}
	len=1;
	while(len<=2*all)len<<=1;
	//len=128;
	if(bcnt!=acnt){
		printf("0\n");
		return 0;
	}
	fact[0]=1;
	for(int i=1;i<=acnt+all+1;++i){
		fact[i]=fact[i-1]*i%mod;
	}
	s.x[all]=reverse(fact[all+1]);
	for(int i=all;i>=1;--i){
		s.x[i-1]=s.x[i]*(i+1)%mod;
	}
	LL res=ksm(s,acnt);
	printf("%lld\n",res*fact[acnt]%mod*fact[all]%mod*fact[acnt+all]%mod);
}