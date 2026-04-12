#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 100005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

#define Mo 998244353
#define g 3

using namespace std;

int i,j,m,n,p,k,NN,rev[N],w[2][N],fac[N],inv[N],AA,BB,A[N],B[N],C[N];

int power(int x,int y)
{
		int sum=1;
		for (;y;y>>=1)
		{
				if (y&1) sum=1ll*sum*x%Mo;
				x=1ll*x*x%Mo;
		}
		return sum;
}

char c[N],s[N];

void NTT(int *A,int f)
{
		int i,j,k,l,t;
		for (i=0;i<NN;++i) if (i<rev[i]) swap(A[i],A[rev[i]]); 
		for (i=1;i<NN;i<<=1)
			for (j=0,t=NN/(i<<1);j<NN;j+=(i<<1))
				for (k=0,l=0;k<i;++k,l+=t)
				{
						int x=A[j+k],y=1ll*A[j+k+i]*w[f][l]%Mo;
						A[j+k]=(x+y)%Mo; A[j+k+i]=(x-y+Mo)%Mo;
				}
		if (f)
		{
				int invn=power(NN,Mo-2);
				for (i=0;i<NN;++i) A[i]=1ll*A[i]*invn%Mo; 
		}
}

int getC(int x,int y)
{
		return 1ll*fac[x]*inv[y]%Mo*inv[x-y]%Mo;
}

int main()
{
		fac[0]=1;
		for (i=1;i<N;++i) fac[i]=1ll*fac[i-1]*i%Mo;
		for (i=0;i<N;++i) inv[i]=power(fac[i],Mo-2);
		scanf("%s",c+1);
		scanf("%s",s+1); n=strlen(c+1);
		for (i=1;i<=n;++i) if (c[i]=='1'&&s[i]=='1') AA++;
							else if (c[i]!=s[i]) BB++;
		BB/=2;
		for (NN=1;NN<n;NN<<=1); NN<<=1; 
		w[0][0]=1; w[0][1]=power(g,(Mo-1)/NN);
		for (i=2;i<N;++i) w[0][i]=1ll*w[0][i-1]*w[0][1]%Mo;
		for (i=0;i<N;++i) w[1][i]=power(w[0][i],Mo-2);
 		for (i=0;i<NN;++i) 
 		{
 				for (j=1,k=i;j<NN;j<<=1,k>>=1) (rev[i]<<=1)|=(k&1);
 		}
 		for (i=0;i<=AA;++i) A[i]=B[i]=inv[i+1];
 		C[0]=1;
		for (j=0;(1<<j)<=BB;++j)
		{
			if (BB&(1<<j)) 
			{
					NTT(C,0); NTT(A,0);
					for (i=0;i<NN;++i) C[i]=1ll*C[i]*A[i]%Mo;
					NTT(C,1); NTT(A,1);
					for (i=AA+1;i<NN;++i) C[i]=0;
			}
			memset(B,0,sizeof(B));
			for (i=0;i<=AA;++i) B[i]=A[i];
			NTT(A,0); NTT(B,0);
			for (i=0;i<NN;++i) A[i]=1ll*A[i]*B[i]%Mo;
			NTT(A,1);
			for (i=AA+1;i<NN;++i) A[i]=0;
		}
		int ans=0;
		for (i=0;i<=AA;++i)
		{
			int sum=1ll*fac[BB]*fac[i+BB]%Mo*C[i]%Mo;
			sum=1ll*sum*getC(AA,i)%Mo*getC(AA+BB,i+BB)%Mo;
			sum=1ll*sum*fac[i]%Mo;
			sum=1ll*sum*fac[AA-i]%Mo*fac[AA-i]%Mo;
			(ans+=sum)%=Mo;
		}
		printf("%d\n",ans);
}
