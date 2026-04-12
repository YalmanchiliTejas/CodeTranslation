#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 200000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
pair<int,int> q[MN*2+5];
int n,mx=0,Mx,mn=2e9,Mn,A[MN+5],B[MN+5],top=0,s[MN+7];
long long ans;

long long Solve1()
{
	int Mxmn=A[Mn],Mnmx=B[Mx];
	for(int i=1;i<=n;++i)
		Mxmn=min(Mxmn,A[i]),Mnmx=max(Mnmx,B[i]);
//	cout<<"Solve1"<<mn<<" "<<Mxmn<<" "<<Mnmx<<" "<<mn<<endl;
	return 1LL*(mx-Mxmn)*(Mnmx-mn);	
}

bool Solve(int x)
{
	memset(s,0,sizeof(s));int Kind=0;
	for(int i=1,j=1;i<=top;++i)
	{
		for(;j<=top&&q[j].first<=q[i].first+x;++j) if(!s[q[j].second]++) ++Kind;
		if(Kind==n) return true;
		if(!--s[q[i].second]) --Kind;
	}
	return false;
}

long long Solve2()
{
	for(int i=1;i<=n;++i) if(i!=Mx&&i!=Mn) q[++top]=make_pair(A[i],i),q[++top]=make_pair(B[i],i);
	q[++top]=make_pair(B[Mx],n+1);q[++top]=make_pair(A[Mn],n+2);sort(q+1,q+top+1);
	int l=0,r=1e9,mid,res;
	while(l<=r)
	{
		mid=l+r>>1;
		if(Solve(mid)) res=mid,r=mid-1;
		else l=mid+1;	
	} 
	return 1LL*(mx-mn)*res;
} 

int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		A[i]=read();B[i]=read();
		if(A[i]<B[i]) swap(A[i],B[i]);
		if(A[i]>mx) mx=A[i],Mx=i;
		if(B[i]<mn) mn=B[i],Mn=i;	
	}
	ans=Solve1();
//	ans=4e18;
	if(Mx!=Mn) ans=min(ans,Solve2());
	printf("%lld\n",ans);
	return 0;
}

