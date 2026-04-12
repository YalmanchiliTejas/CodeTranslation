#include <cstdio>
#include <cmath>
using namespace std;
const long long NR=110;
char s[NR];
long long l,k,ans,n,a[NR],b[NR];
bool flag;
int main()
{
	scanf("%s\n%lld",s,&k);
	while(s[l])
	{
		l++;
	}
	for(long long i=0;i<l;i++)
	{
		a[i+1]=s[i]-'0';
	}
	if(k==1)
	{
		for(long long i=1;i<=l;i++)
		{
			for(long long x=1;x<=9;x++)
			{
				long long tmp=b[i];
				b[i]=x;
				flag=1;
				for(long long w=1;w<=l;w++)
				{
					if(b[w]>a[w])
					{
						flag=0;
						break;
					}
					if(b[w]<a[w])
					{
						flag=1;
						break;
					}
				}
				ans+=flag;
				b[i]=tmp;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	if(k==2)
	{
		for(long long i=1;i<=l;i++)
		{
			for(long long j=i+1;j<=l;j++)
			{
				for(long long x=1;x<=9;x++)
				{
					for(long long y=1;y<=9;y++)
					{
						long long tmp=b[i],TMP=b[j];
						b[i]=x;
						b[j]=y;
						flag=1;
						for(long long w=1;w<=l;w++)
						{
							if(b[w]>a[w])
							{
								flag=0;
								break;
							}
							if(b[w]<a[w])
							{
								flag=1;
								break;
							}
						}
						ans+=flag;
						b[i]=tmp;
						b[j]=TMP;
					}
				}
			}
		}
		printf("%lld",ans);
		return 0;
	}
	for(long long i=1;i<=l;i++)
	{
		for(long long j=i+1;j<=l;j++)
		{
			for(long long k=j+1;k<=l;k++)
			{
				long long L,r,mid;
				L=0;
				r=729;
				while((r-L)>1)
				{
					mid=(L+r)>>1;
					long long tmp=b[i],TMP=b[j],temp=b[k];
					b[i]=(mid/81)+1;
					b[j]=((mid/9)%9)+1;
					b[k]=(mid%9)+1;
					flag=1;
					for(long long w=1;w<=l;w++)
					{
						if(b[w]>a[w])
						{
							flag=0;
							break;
						}
						if(b[w]<a[w])
						{
							flag=1;
							break;
						}
					}
					b[i]=tmp;
					b[j]=TMP;
					b[k]=temp;
					if(flag)
					{
						L=mid;
					}
					else
					{
						r=mid;
					}
				}
				ans+=(L+1);
				long long tmp=b[i],TMP=b[j],temp=b[k];
					b[i]=b[j]=b[k]=1;
					flag=1;
					for(long long w=1;w<=l;w++)
					{
						if(b[w]>a[w])
						{
							flag=0;
							break;
						}
						if(b[w]<a[w])
						{
							flag=1;
							break;
						}
					}
					b[i]=tmp;
					b[j]=TMP;
					b[k]=temp;
					if(flag==0)
					{
						ans--;
					}
			}
		} 
	}
	printf("%lld",ans);
	return 0;
}