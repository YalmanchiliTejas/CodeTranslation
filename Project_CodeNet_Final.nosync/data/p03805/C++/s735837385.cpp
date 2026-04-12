#include<bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define ll long long
#define mod 1000000007
#define bitcount    __builtin_popcountll
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define pi pair<int,int>
int a[10][10],ans;
void f(int b[],int pos,int n)
{
	if(pos==n)
	{
		int i=0;;
		for(i=1;i<n;i++)
		{
			//printf("%d ",b[i]);
			if(!a[b[i]][b[i-1]])
				break;
		}
		//printf("\n");
		if(i==n)
			ans++;
		return;
	}
	for(int i=pos;i<n;i++)
	{
		swap(b[i],b[pos]);
		f(b,pos+1,n);
		swap(b[i],b[pos]);
	}
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,i,j,k,b[10];
    sd(n);
    sd(m);
    for(i=0;i<m;i++)
    {
    	sd(j);
    	sd(k);
    	a[j][k]=1;
    	a[k][j]=1;
    }
    for(i=0;i<n;i++)
    	b[i]=i+1;
    f(b,1,n);
    printf("%d",ans);
    return 0;
}