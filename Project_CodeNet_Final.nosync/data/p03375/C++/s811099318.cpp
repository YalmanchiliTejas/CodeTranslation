#include<iostream>
#include<cstdio>
#include<cstring>

typedef long long ll;

const int N=3033;

ll qpow(ll a,ll b,ll MOD){ll c=1;for(;b;b>>=1,a=a*a%MOD)if(b&1)c=c*a%MOD;return c;}

int n,MOD;

int f[N][N],C[N][N];

int ans;

int main()
{
	scanf("%d%d",&n,&MOD);

	f[0][0]=1;
	for(int i=1;i<N;i++)
		for(int j=0;j<N;j++)
			f[i][j]=((ll)f[i-1][j]*j+f[i-1][j-1]+f[i-1][j])%MOD;
	for(int i=0;i<N;i++)C[i][0]=1;
	for(int i=1;i<N;i++)
		for(int j=1;j<N;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;

	int tmp=qpow(2,n,MOD-1);
	ans=qpow(2,tmp,MOD);

	for(int cnt=1;cnt<=n;cnt++)
	{
		int sum=0;

		int u=qpow(2,n-cnt,MOD-1);
		int v=qpow(2,n-cnt,MOD);

		for(int z=0;z<=cnt;z++)
		{
			int res=f[cnt][z];

			res=(ll)res*qpow(v,z,MOD)%MOD*qpow(2,u,MOD)%MOD;

//			for(int x=0;x<=cnt;x++)
//			{
//				int fk=str[x][z]*qpow(v,z,MOD)%MOD*qpow(2,u,MOD)%MOD;
//				fk=(ll)fk*C[cnt][x]%MOD;
//				res=(res+fk)%MOD;
//			}

			sum=(sum+res)%MOD;
		}

//		printf("cnt = %d , sum = %d\n",cnt,sum);

		sum=(ll)sum*C[n][cnt]%MOD;

		if(cnt&1)ans=(ans-sum)%MOD;
		else ans=(ans+sum)%MOD;
	}

	ans=(ans+MOD)%MOD;
	printf("%d\n",ans);

	return 0;
}
