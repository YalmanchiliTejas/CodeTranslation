#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200200],f[200200][2];
signed main()
{
	scanf("%lld",&n);
	int i=1;
	while(i<=n)
	{
		scanf("%lld",&a[i]);
		++i;
	}
	f[0][1]=0;
	f[1][1]=a[1];
	f[1][0]=0;
	i=2;
	while(i<=n)
	{
		if(i&1)
		{
			f[i][0]=max(f[i-1][1],f[i-2][0]+a[i]);
			f[i][1]=f[i-2][1]+a[i];
		}
		else f[i][1]=max(f[i-2][1]+a[i],f[i-1][1]);
		++i;
	}
	printf("%lld\n",f[n][!(n&1)]);
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//int n,a[200200],pre[200200][2],sub[200200][2],ans=0;
//int mxl[200200],mxr[200200];
//signed main()
//{
//	scanf("%lld",&n);
//	
//	int i=1;
//	while(i<=n)
//	{
//		scanf("%lld",&a[i]);
//		++i;
//	}
//	
//	if(!(n&1))
//	{
//		pre[0][0]=0;
//		pre[0][1]=0;
//		sub[n+1][0]=0;
//		sub[n+1][1]=0;
//		i=1;
//		while(i<=n)
//		{
//			pre[i][0]=pre[i-1][0];
//			pre[i][1]=pre[i-1][1];
//			pre[i][i&1]+=a[i];
//			++i;
//		}
//		i=n;
//		while(i>=1)
//		{
//			sub[i][0]=sub[i+1][0];
//			sub[i][1]=sub[i+1][1];
//			sub[i][i&1]+=a[i];
//			--i;
//		}
//		ans=0;
//		i=0;
//		while(i<=n)
//		{
//			ans=max(ans,pre[i][1]+sub[i+1][0]);
//			i+=2;
//		}
//		printf("%lld\n",ans);
//		return 0;
//	}
//	
//	if(n==3)
//	{
//		printf("%lld\n",max(max(a[1],a[2]),a[3]));
//		return 0;
//	}
//	
//	pre[0][0]=0;
//	pre[0][1]=0;
//	sub[n+1][0]=0;
//	sub[n+1][1]=0;
//	
//	i=1;
//	while(i<=n)
//	{
//		pre[i][0]=pre[i-1][0];
//		pre[i][1]=pre[i-1][1];
//		pre[i][i&1]+=a[i];
//		++i;
//	}
//	i=n;
//	while(i>=1)
//	{
//		sub[i][0]=sub[i+1][0];
//		sub[i][1]=sub[i+1][1];
//		sub[i][i&1]+=a[i];
//		--i;
//	}
//	
//	mxl[0]=sub[1][0];
//	i=2;
//	while(i<n)
//	{
//		mxl[i]=max(mxl[i-2],pre[i][1]+sub[i+1][0]);
//		i+=2;
//	}
//	mxr[n+1]=pre[n][0];
//	i=n-1;
//	while(i>1)
//	{
//		mxr[i]=max(mxr[i+2],pre[i-1][0]+sub[i][1]);
//		i-=2;
//	}
//	
//	i=3;
//	while(i<n)
//	{
//		ans=max(ans,mxl[i-1]+mxr[i+1]-sub[i][0]-pre[i][0]);
//		i+=2;
//	}
////	i=n+1;
////	while(i>1)
////	{
////		ans=max(ans,max(sub[i][0],sub[i][1])+max(pre[i-2][0],pre[i-2][1]));
////		i-=2;
////	}
//	printf("%lld\n",max(max(ans,pre[n-1][0]),sub[2][0]));
//	return 0;
//}
/*
#include<bits/stdc++.h>
using namespace std;
long long ans=0;
char s[4040];
int n;
int sr[4040],sg[4040],sb[4040];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	sr[0]=0;
	sg[0]=0;
	sb[0]=0;
	int i=1,j=1,k=1;
	while(i<=n)
	{
		sr[i]+=sr[i-1]+(s[i]=='R');
		sg[i]+=sg[i-1]+(s[i]=='G');
		sb[i]+=sb[i-1]+(s[i]=='B');
		++i;
	}
	j=1;
	while(j<n)
	{
		k=j+1;
		while(k<=n)
		{
			if(s[j]!=s[k])
			{
				if(((s[j]=='R')&&(s[k]=='G'))||((s[j]=='G')&&(s[k]=='R'))) ans+=sb[j-1];
				if(((s[j]=='R')&&(s[k]=='B'))||((s[j]=='B')&&(s[k]=='R'))) ans+=sg[j-1];
				if(((s[j]=='B')&&(s[k]=='G'))||((s[j]=='G')&&(s[k]=='B'))) ans+=sr[j-1];
				int tt=k-j;
				if(j-tt>=1)
				{
					i=j-tt;
					if((s[i]!=s[j])&&(s[i]!=s[k])&&(s[j]!=s[k])) --ans;
				}
			}
			++k;
		}
		++j;
	}
	printf("%lld\n",ans);
	return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1000000007;
int pri[100100],phi[100100],tot=0;
int n,kk,ans=0;
inline int poww(int a,int b,int mod)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
inline void prep()
{
	phi[1]=1;
	int i=2,j=1;
	while(i<=100000)
	{
		if(!phi[i])
		{
			pri[++tot]=i;
			phi[i]=i-1;
		}
		j=1;
		while((j<=tot)&&(pri[j]*i<=100000))
		{
			if(i%pri[j]) phi[i*pri[j]]=phi[i]*(pri[j]-1);
			else
			{
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			++j;
		}
		++i;
	}
}
signed main()
{
	prep();
	scanf("%lld%lld",&n,&kk);
	prep();
	int i=1;
	while(i<=kk)
	{
		ans+=phi[i]*poww(kk/i,n,mod);
		ans%=mod;
		++i;
	}
	printf("%lld\n",ans);
	return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int kk;
long long ans=0;
int main()
{
	scanf("%d",&kk);
	int i=1,j=1,k=1;
	while(i<=kk)
	{
		j=1;
		while(j<=kk)
		{
			k=1;
			while(k<=kk)
			{
				ans+=1ll*__gcd(__gcd(i,j),k);
				++k;
			}
			++j;
		}
		++i;
	}
	printf("%lld\n",ans);
	return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
int main()
{
	scanf("%lld",&n);
	ans=(1+n)*n/2;
	long long tmp=n/3ll;
	if(n>=3) ans-=(tmp*3ll+3ll)*tmp/2ll;
	tmp=n/5ll;
	if(n>=5) ans-=(tmp*5ll+5ll)*tmp/2ll;
	tmp=n/15ll;
	if(n>=15) ans+=(tmp*15ll+15ll)*tmp/2ll;
	printf("%lld\n",ans);
	return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	int i=1,p=1;
	while(i<=5)
	{
		int tmp=n%(p*10);
		tmp/=p;
		if(tmp==7)
		{
			printf("Yes\n");
			return 0;
		}
		p*=10;
		++i;
	}
	printf("No\n");
	return 0;
}
*/