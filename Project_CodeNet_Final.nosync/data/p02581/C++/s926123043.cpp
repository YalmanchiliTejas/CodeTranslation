#include<cstdio>
#include<cstring>
#define N 6031
using namespace std;
int f[N][N],wei[N],last[N],before[N],sbefore[N],right[N];
int first[N][N],second[N][N],g[N],h[N],bz[N];
bool spd[N];
int a[N];
int n;
int min(int x,int y)
{
	if (x<y) return x;
	return y;
}
bool pd(int x,int y)
{
	if (sbefore[x]==-1||sbefore[y]==-1) return false;
	if (x==0||y==0) return true;
	if (x==y) return true;
	if (wei[x]==wei[y]) return false;
	if (last[x]==y||sbefore[x]==y) return false;
	if (last[y]==x||sbefore[y]==x) return false;
	if (wei[x]<=wei[sbefore[y]]||(wei[y]<=wei[sbefore[x]])) return false;
	if (wei[y]==wei[last[y]]&&wei[last[y]]==wei[last[last[y]]]) return false;
	if (wei[x]==wei[last[x]]&&wei[last[x]]==wei[last[last[x]]]) return false;
	if (wei[x]!=wei[last[x]]&&wei[sbefore[y]]<wei[x]&&wei[y]>wei[last[x]])
	{
	//	if (!(wei[y]==wei[last[y]]&&wei[last[y]]==wei[last[last[y]]])) return false;
		return false;	
	}
	if (wei[y]!=wei[last[y]]&&wei[sbefore[x]]<wei[y]&&wei[x]>wei[last[y]])
	{
	//	if (!(wei[x]==wei[last[x]]&&wei[last[x]]==wei[last[last[x]]])) return false;
		return false;
	}	
	return true;
}
int max(int x,int y)
{
	if (x<y) return y;
	return x;
}
int main()
{
	scanf("%d",&n);
	n*=3;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n-5;i++) wei[i+5]=(i-1)/3+2;
	for (int i=1;i<=5;i++) wei[i]=1;
	for (int i=1;i<=n;i++) before[i]=-1;
	for (int i=1;i<=n;i++)
		if (wei[i]!=wei[i+1]) right[wei[i]]=i;
	memset(bz,0,sizeof(bz));
	int add=0;
	for (int i=1;i<=5;i++)
	{
		bz[a[i]]++;
	}
	memset(spd,true,sizeof(spd));
	for (int i=1;i<=n;i++)
		if (bz[i]>=3) add++;
	int sps1=0;
	if (add>=1)
	{
		for (int i=1;i<=n;i++)
			if (bz[i]>=3)
				sps1=i;
	}
	for (int i=6;i<n;i++)
	{
		if (wei[i+1]!=wei[i])
		{
			if (a[i]==a[i-1]&&a[i-1]==a[i-2]) 
			{
				add++;
				spd[i]=spd[i-1]=spd[i-2]=false;
			}
		}
	}
	int cnt=0;
	if (sps1==0) cnt=1e9;
	for (int i=1;i<=n;i++)
	{
		if (!spd[i]) continue; 
		if (i<=5&&(a[i]==sps1)) cnt++;
		if (a[i]==sps1&&i<=5&&cnt<=3) 
		{
			last[i]=-1;
			continue;
		}
		last[i]=before[a[i]];
		before[a[i]]=i;
	}
	for (int i=1;i<=n;i++) 
		if (last[i]==-1) sbefore[i]=-1;
		else sbefore[i]=last[last[i]];
	for (int i=6;i<=n;i++)
		for (int j=6;j<=n;j++)
		{
			if  (i==18&&j==18)
			{
				n++;n--;
			}
			if (spd[i]&&spd[j]&&pd(i,j))
			{
				f[i][j]=2;
				if (i==0) f[i][j]--;
				if (j==0) f[i][j]--;
				if (i!=0&&i==j) f[i][j]--;
			}
			else	f[i][j]=-1e9;
		}
	bool bo=pd(26,27);
	for (int i=1;i<=n;i++) first[0][i]=f[0][i];
	memset(g,0,sizeof(g));
	for (int i=0;i<=n;i++) g[i]=h[i]=-1e9;
	for (int i=6;i<=n;i++)
	{
		second[i][0]=f[i][0];
		g[i]=max(g[i],g[i-1]);
		h[i]=max(h[i],h[i-1]);
		for (int j=6;j<=n;j++)
			if(spd[i]&&spd[j]&&pd(i,j))
			{
				if (i==28&&j==25)
				{
					n++;n--;
				}
				int r=sbefore[i]-1;
				if (r>=i) r=i-1;
				int p;
				if (i==j)
				{
					f[i][j]=max(f[i][j],first[r][j]);
					for (int k=sbefore[i]+1;k<=right[wei[sbefore[i]]];k++)
						if (k<=i-1&&k!=last[i])
							f[i][j]=max(f[i][j],f[k][j]);
					p=wei[min(sbefore[i],sbefore[j])]-1;
					f[i][j]=max(f[i][j],g[right[p]]+1);
					for (int k=right[p]+1;k<=right[p]+3;k++)
					{
						if (!((k<sbefore[i]||a[k]!=a[i]))) continue;
						f[i][j]=max(f[i][j],first[right[p]][k]+1);
						f[i][j]=max(f[i][j],second[k][right[p]]+1);
					}
					for (int k1=right[p]+1;k1<=right[p]+3;k1++)
						for (int k2=right[p]+1;k2<=right[p]+3;k2++)
							if ((k1<sbefore[i]||a[k1]!=a[i])&&(k2<sbefore[i]||a[k2]!=a[i]))
								f[i][j]=max(f[i][j],f[k1][k2]+1);
				}
				p=wei[min(sbefore[i],sbefore[j])]-1;
				if (i!=j)
				{	
					for (int k=right[p]+1;k<=right[p]+3;k++)
					{
						if (!((k<sbefore[i]||a[k]!=a[i]))) continue;
						if (!((k<sbefore[j]||a[k]!=a[j]))) continue;
						f[i][j]=max(f[i][j],first[right[p]][k]+2);
						f[i][j]=max(f[i][j],second[k][right[p]]+2);
					}
					for (int k1=right[p]+1;k1<=right[p]+3;k1++)
						for (int k2=right[p]+1;k2<=right[p]+3;k2++)
							if ((k1<sbefore[i]||a[k1]!=a[i])&&(k2<sbefore[i]||a[k2]!=a[i]))
								if ((k1<sbefore[j]||a[k1]!=a[j])&&(k2<sbefore[j]||a[k2]!=a[j]))
									f[i][j]=max(f[i][j],f[k1][k2]+2);
					f[i][j]=max(f[i][j],g[right[p]]+2);
				}
				if (i!=j)
				{
					f[i][j]=max(f[i][j],h[right[p]]+2);
					for (int k=right[p]+1;k<=right[p]+3;k++)
						if (wei[k]<=wei[sbefore[i]]&&(k<sbefore[i]||a[k]!=a[i]))
							if (wei[k]<=wei[sbefore[j]]&&(k<sbefore[j]||a[k]!=a[j]))
									f[i][j]=max(f[i][j],f[k][k]+2);
				}
				r=j;
				if (r>i-1) r=i-1;
				if (r>sbefore[i]-1)
					r=sbefore[i]-1;
				f[i][j]=max(f[i][j],first[r][j]+1);
				if (r==sbefore[i]-1)
					for (int k=sbefore[i]+1;k<=right[wei[sbefore[i]]];k++)
						if (k<=j&&k<=i-1&&k!=last[i])
							f[i][j]=max(f[i][j],f[k][j]+1);
				r=i;
				if (r>j-1) r=j-1;
				if (r>sbefore[j]-1) r=sbefore[j]-1;
				for (int k=sbefore[j]+1;k<=right[wei[sbefore[j]]];k++)
					if (k<=i&&k<=j-1&&k!=last[j])
						f[i][j]=max(f[i][j],f[i][k]+1);
				f[i][j]=max(f[i][j],second[i][r]+1);
				second[i][j]=max(f[i][j],second[i][j-1]);
				g[max(i,j)]=max(g[max(i,j)],f[i][j]);
			}
			else	second[i][j]=second[i][j-1];
		for (int j=1;j<=n;j++)
			first[i][j]=max(f[i][j],first[i-1][j]);
		h[i]=max(h[i],f[i][i]);
	}
	int max=0;
	for (int i=6;i<=n;i++)
	{
		for (int j=6;j<=n;j++)
		{
	//		printf("%d ",f[i][j]);
			if (max<f[i][j]) max=f[i][j];
		//	if (max==6)
		//	{
		//		max++;max--; 
		//	}
		}
	//	printf("\n");
	}
	printf("%d\n",max+add);
}
